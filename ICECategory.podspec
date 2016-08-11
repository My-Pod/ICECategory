Pod::Spec.new do |s|
s.name             = 'ICECategory'
s.version          = '1.0.3'
s.summary          = '常用的Category'
s.description      = <<-DESC
TODO: This is a simple custom Category.
DESC

s.homepage         = 'https://github.com/My-Pod/ICECategory'
s.license          = { :type => 'MIT', :file => 'LICENSE' }
s.author           = { 'gumengxiao' => 'rare_ice@163.com' }
s.source           = { :git => 'https://github.com/My-Pod/ICECategory.git', :tag => s.version.to_s }

s.ios.deployment_target = '7.0'

s.source_files = 'ICECategory/*.{h,m}'

    s.subspec 'Foundation' do |ss|
        ss.source_files = 'ICECategory/Foundation/*.{h,m}'
    end

    s.subspec 'UIKit' do |ss|
        ss.source_files = 'ICECategory/UIKit/*.{h,m}'
    end

end
