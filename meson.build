project('skeleton', 'cpp', default_options: ['cpp_std=c++20'])

if host_machine.system() == 'darwin'
  add_project_arguments(
    '-U_LIBCPP_ENABLE_ASSERTIONS',
    '-D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_EXTENSIVE',
    language: 'cpp',
  )
endif

gtest_dep = dependency('gtest', fallback: ['gtest', 'gtest_dep'])
executable('my_test', 'test.cpp', dependencies: gtest_dep)
executable('skeleton', 'main.cpp')
