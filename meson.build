project('skeleton', 'cpp', default_options: ['cpp_std=c++20'])

gtest_dep = dependency('gtest', fallback: ['gtest', 'gtest_dep'])
executable('test', 'test.cpp', dependencies: gtest_dep)
executable('skeleton', 'main.cpp')
