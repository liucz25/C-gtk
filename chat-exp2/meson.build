project('chat_exp2',['c','cpp'],default_options: ['cpp_std=c++20'])

deps = dependency('glib-2.0')

res = run_command('./getMainSrc.sh',check: true)
srcs = res.stdout().strip().split('\n')

executable('chatExp2', srcs, dependencies: deps)