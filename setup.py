from distutils.core import setup, Extension

module = Extension('santa', sources = ['data.c','santa.c','pysanta.c'])

setup (name = 'santa',
        version = '1.0',
        description = 'Traveling Santa Problem',
        ext_modules = [module])
