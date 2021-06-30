1. One test will failed if you use python2 instead of python3.
  > Add this line to your ~/.bashrc file  
  'export OPTICKS_PYTHON=python3'

2. Some tests may fail if you didn't set the key to the geocache.
  > Add this line to your ${workdir}/.opticks_config file  
  `export OPTICKS_KEY=OKX4Test.X4PhysicalVolume.World0xc15cfc00x40f7000_PV.803ebc37074ac640fee2727a86381399`  

3. OpenGL settings
  > 'export MESA_GL_VERSION_OVERRIDE=4.1'  
  'export MESA_GLSL_VERSION_OVERRIDE=410'
