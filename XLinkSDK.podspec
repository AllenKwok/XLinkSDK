#
# Be sure to run `pod lib lint XLinkSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'XLinkSDK'
  s.version          = '6.1.2.33'
  s.summary          = 'XLink crop Iot SDK for iOS.'
  s.description      = <<-DESC
    XLink crop Iot SDK for iOS.more info can view in www.xlink.cn.
                       DESC

  s.homepage         = 'https://github.com/AllenKwok/XLinkSDK'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'AllenKwok' => 'guopeilun@xlink.cn' }
  s.source           = { :git => 'https://github.com/AllenKwok/XLinkSDK-iOS.git', :tag => s.version }
  s.ios.deployment_target = '8.0'
  s.frameworks = 'Foundation'
  s.source_files = 'include/*.h', 'include/**/*.h'
  s.vendored_libraries = 'lib/*.a'
  s.ios.library =  'stdc++', 'z'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
end
