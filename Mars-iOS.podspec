# encoding:utf-8
#
# Be sure to run `pod lib lint WeChatQRCodeScanner_Swift.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name = "Mars-iOS"
  s.version = "1.0.3"
  s.summary = "Cocoapods for tencent mars"
  s.description = <<-DESC
                      腾讯Mars pod版本,swift、oc皆可使用
                      DESC

  s.homepage = "hhttps://github.com/ljyKangaroo/Mars-iOS"

  s.license = { :type => "MIT", :file => "LICENSE" }

  s.author = { "ljyKangaroo" => "test.com" }

  s.source = { :git => "https://github.com/ljyKangaroo/Mars-iOS.git", :tag => s.version.to_s }

  s.requires_arc = true

  s.static_framework = true

  s.default_subspec = "Core"

  s.ios.deployment_target = "13.0"

  s.ios.libraries = "z", "c++", "resolv.9"

  s.ios.frameworks = "Foundation", "CoreLocation", "CoreTelephony", "SystemConfiguration"

  # s.prefix_header_file = false
  s.pod_target_xcconfig = {
    "CLANG_WARN_DOCUMENTATION_COMMENTS" => "NO",
    "BUILD_LIBRARY_FOR_DISTRIBUTION" => "YES",
  }

  s.user_target_xcconfig = {
    "OTHER_LDFLAGS" => [
        "-ld_classic",
        "-Wl",
    ],
  }

  s.preserve_paths = [
    "Mars/Frameworks",
    "script/build.sh",
    "script/downloadlib.sh",
  ]

  # s.prepare_command = <<-CMD
  #   script/build.sh "master"
  # CMD

  s.prepare_command = <<-CMD
    script/downloadlib.sh "lib-v1"
  CMD

  s.subspec "Core" do |core|
    core.source_files = [
      "Mars/Frameworks/*.{h,cc}",
      "Mars/Classes/Xlog/*.{h,cc,m,mm}",
      "Mars/Classes/Core/**/*.{h,cc,m,mm}",
      "Mars/Frameworks/mars.framework/**/*.h",
    ]

    core.public_header_files = [
      "Mars/Classes/**/*.h",
    ]

    core.project_header_files = [
      "Mars/Frameworks/*.h",
      "Mars/Frameworks/mars.framework/**/*.h",
    ]

    core.vendored_frameworks = [
      "Mars/Frameworks/mars.framework",
    ]
  end

  s.subspec "Swift" do |ss|
    ss.source_files = [
      "Mars/Classes/Bridge/*.{h,m,mm}",
    ]
    ss.dependency "Mars-iOS/Core"
  end

  s.subspec "Xlog" do |ss|
    ss.source_files = [
      "Mars/Classes/Xlog/*.{h,cc,m,mm}",
      "Mars/Frameworks/Xlog/mars.framework/**/*.h",
    ]

    ss.project_header_files = [
      "Mars/Frameworks/Xlog/mars.framework/**/*.h",
    ]

    ss.vendored_frameworks = [
      "Mars/Frameworks/Xlog/mars.framework",
    ]
  end

  s.subspec "Xlog.Swift" do |ss|
    ss.source_files = [
      "Mars/Classes/Bridge/XloggerManager.{h, mm}",
    ]
    ss.dependency "Mars-iOS/Xlog"
  end
end
