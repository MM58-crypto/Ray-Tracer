if(EXISTS "/home/mm/my-ray-tracer/build/ray-tracer-tests[1]_tests.cmake")
  include("/home/mm/my-ray-tracer/build/ray-tracer-tests[1]_tests.cmake")
else()
  add_test(ray-tracer-tests_NOT_BUILT ray-tracer-tests_NOT_BUILT)
endif()