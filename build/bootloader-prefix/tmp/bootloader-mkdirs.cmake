# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Dipan/esp/esp-idf/components/bootloader/subproject"
  "E:/esp_workspace/vts_fw_gen1_1.0.0/build/bootloader"
  "E:/esp_workspace/vts_fw_gen1_1.0.0/build/bootloader-prefix"
  "E:/esp_workspace/vts_fw_gen1_1.0.0/build/bootloader-prefix/tmp"
  "E:/esp_workspace/vts_fw_gen1_1.0.0/build/bootloader-prefix/src/bootloader-stamp"
  "E:/esp_workspace/vts_fw_gen1_1.0.0/build/bootloader-prefix/src"
  "E:/esp_workspace/vts_fw_gen1_1.0.0/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/esp_workspace/vts_fw_gen1_1.0.0/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/esp_workspace/vts_fw_gen1_1.0.0/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
