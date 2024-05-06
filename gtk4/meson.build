project('exp2','cpp')
fs = import('fs')

depGtk = dependency('gtk4')

srcs = fs.read('srcs').strip().split('\n')

executable('exp2',srcs,dependencies:[depGtk])
