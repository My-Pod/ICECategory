Pod::Spec.new do |s|
s.name             = 'ICECategory'
s.version          = '1.0.1'
s.summary          = '常用的Category'
s.description      = <<-DESC
TODO: This is a simple custom Category.
DESC

s.homepage         = 'https://github.com/My-Pod/ICECategory'
s.license          = { :type => 'MIT', :file => 'LICENSE' }
s.author           = { 'gumengxiao' => 'rare_ice@163.com' }
s.source           = { :git => 'https://github.com/My-Pod/ICECategory.git', :tag => s.version.to_s }

s.ios.deployment_target = '7.0'

s.source_files = 'ICECategory/*.{h,m}','ICECategory/Foundation/*.{h,m}','ICECategory/UIKit/*.{h,m}'




end
