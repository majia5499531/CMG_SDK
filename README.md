#融媒云SDK说明文档
##一、总体说明

```
本SDK包含了资讯列表页，资讯详情页、视频详情页等UI页面，配合管理后台可以快速实现新闻上稿、排版和内容推荐。

1.如果您无需自定义资讯列表的UI样式，可以使用SDK自带的UI页面，包含资讯列表页、资讯详情页，短视频页等
2.如果您需要自定义资讯列表的UI样式，可以使用requestContentList等方法，直接获取资讯瀑布流的原始数据，自行实现其UI渲染代码



由于本SDK包含分享、点赞、评论等涉及用户操作的一些功能，需要您实现以下回调方法：
1.分享功能
2.登录功能
3.用户基本信息	(用户ID，手机号，昵称，头像)


```





##二、Android端集成步骤

1.使用Gradle集成SDK

```
<1>.在模块的build.gradle中添加dependencies {
 implementation 'com.github.aaa31210aaa:SzrmSdk:latest.release'
}


<2>.在app级别的 build.gradle 中 
buildscript{
repositories {
 		...
 		maven {url 'https://jitpack.io'}
 		maven {
            url 'http://172.30.101.24:8081/repository/maven-releases/'
            //gradle 如果大于7.0 需要加入下面这一句
            allowInsecureProtocol true
        }
	}
}

allprojects{
	//...同上
}

```

2.在自己的Application中初始化中加入

```
  /**
     * isDebug 是否为测试环境
     * appId 你的appId
     * appkey 你的appKey
     */
    @Override
    public void onCreate() {
        super.onCreate();
        ...
 AppInit.init(this,false, "your_appId","your_appKey");
       OkGoUtils.initOkGo(this);
}

```

3.使用单例类去实现SdkParamCallBack接口 实现其中的方法

```
setSdkUserInfo 设置用户信息
shared  可以拿到分享要素
toLogin 实现跳转登录页面

SdkInteractiveParam.getInstance().setSdkCallBack(new SdkParamCallBack() {
    @Override
    public SdkUserInfo setSdkUserInfo(SdkUserInfo sdkUserInfo) {
        return null;
    }

    @Override
    public void shared(ShareInfo shareInfo) {

    }

    @Override
    public void toLogin() {

    }
});

```





##三、iOS端集成步骤

1.使用Cocoapods集成SDK

```
在podfile添加

pod 'CMG_SDK', :git => 'https://github.com/majia5499531/CMG_SDK.git'

执行pod install

```


2.修改工程配置

```
<1>在info.plist文件中添加权限配置

NSPhotoLibraryUsageDescription		支持保存新闻图片到您的相册

<2>关闭BitCode的使用

Targets -> Build Settings -> Enable bitcode     改为 NO

```


3.初始化SDK，并实现SZDelegate协议

```
#import <SZManager.h>
...其他
@interface SZAppDelegate ()<SZDelegate>
@end


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    ...其他
    
	//SDK配置
	//UAT_ENVIROMENT 表示UAT环境，生产环境请选 PRD_ENVIROMENT
    [SZManager initWithAppId:@"12333" appKey:@"00000" appDelegate:self enviroment:UAT_ENVIROMENT];
    
}


//实现SDK协议方法


//获取用户信息，用户未登录则传nil
-(SZUserInfo *)onGetUserInfo{
}

//分享事件
-(void)onShareAction:(SZ_SHARE_PLATFORM)platform title:(NSString*)title image:(NSString*)imgurl desc:(NSString*)desc URL:(NSString*)url{
}

//跳转到登录页
-(void)onLoginAction{
}

```


##四、SDK的使用

###1.使用SDK的UI

```
Android：

//跳转到资讯首页  
Intent intent = new Intent(MainActivity.this, WebActivity);
startActivity(intent);
```

```
iOS：

//引入SZMediaVC，SZMediaVC为资讯列表页
#import <SZMediaVC.h>

//跳转到资讯首页
SZMediaVC * web = [[SZMediaVC alloc]init];
[self.navigationController pushViewController:web animated:YES];


```


###2.自定义UI

```
Android：

//获取列表数据 调用
SzrmRecommend.getInstance().requestContentList("open");

//通过LiveData拿到接口数据
SzrmRecommend.getInstance().contentsEvent.observe(MainActivity.this, new Observer<List<SZContentModel.DataDTO.ContentsDTO>>() {
                    @Override
                    public void onChanged(List<SZContentModel.DataDTO.ContentsDTO> contentsDTOS) {
                    //数据
                    }
                });
                
//进入新闻详情页
SzrmRecommend.getInstance().routeToDetailPage(SZContentModel);
```

```
iOS:

//引入SZManagers
#import "SZManager.h"

//请求资讯列表数据，返回一个包含SZContentModel数组
[SZManager requestContentList:10 Success:^(NSArray<SZContentModel *> * data) {
		//数据
    } Error:^(NSString *msg) {
        
    } Fail:^(NSError *error) {
        
    }];
    
    
//在列表点击等事件中，调用路由方法，进入视频详情页
//传入当前VC的NavigationController，和获得的SZContentModel
[SZManager routeToDetailPage:self.navigationController content:model];
    
```
