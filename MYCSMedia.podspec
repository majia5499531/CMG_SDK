
Pod::Spec.new do |s|
  s.name             = 'MYCSMedia'
  s.version          = '1.3.1'
  s.summary          = 'News & Video Components'
  s.description      = 'News & Video Components'
  s.homepage         = 'https://git.zhcs.csbtv.com/fuse/fuse-ios-sdk'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'majia5499531@163.com' => '5307460+azbura@user.noreply.gitee.com' }
  s.source           = { :git => 'https://git.zhcs.csbtv.com/fuse/fuse-ios-sdk.git', :tag => s.version.to_s }
  

  s.ios.deployment_target = '9.0'

  s.source_files = 'MYCSMedia/Classes/**/*'
  
  s.resource_bundles = {
     'CSAssets' => ['MYCSMedia/Assets/*']
   }
  
  s.dependency 'AFNetworking', '>= 4.0'
  s.dependency 'TXLiteAVSDK_Player', '~> 7.1.8775'
  s.dependency 'MMLayout', '>= 0.3.0'
  s.dependency 'Masonry', '>= 1.1.0'
  s.dependency 'SDWebImage', '>= 5.0'
  s.dependency 'FSTextView', '>= 1.8'
  s.dependency 'MJRefresh'
  s.dependency 'YYText'
  s.dependency 'YYModel'
  s.dependency 'WebViewJavascriptBridge'
  s.static_framework = true
  
  
end

