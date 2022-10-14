
Pod::Spec.new do |s|
    s.name             = 'TMKit-iOS'
    s.version          = '1.0.0'
    s.summary          = 'Solutions dedicated to improving project development efficiency'
    s.description      = <<-DESC
    TMKit is a solution dedicated to improving the efficiency of project development. It is designed to allow developers to focus on business needs without spending energy on basic code design. Whether it is the creation of new projects or the maintenance of existing projects, development efficiency and project quality can be greatly improved.
    DESC
    
    s.homepage         = 'https://github.com/TMPub/TMKit-iOS'
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.author           = { 'jieyuan.zhuang' => 'jieyuan.zhuang@transsnet.com' }
    s.source            = { :http => 'https://github.com/TMPub/TMKit-iOS/archive/refs/tags/1.0.0.zip' }
    s.vendored_frameworks = 'Framework/TMKit.xcframework'
    
    s.platform         = :ios, '11.0'
    s.frameworks       = 'Foundation', 'UIKit', 'CoreGraphics'
    s.requires_arc      = true

    s.dependency 'FMDB-InOperator'
    s.dependency 'GZIP'
    s.dependency 'AFNetworking', '~> 4.0'
    s.dependency 'RSSwizzle'
    s.dependency 'UICKeyChainStore'
    s.dependency 'GBDeviceInfo'
            
end
