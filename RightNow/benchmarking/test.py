# import benchmark
# p = Bunch()
# x  = benchmark.Multipole(knl=[0, 1, 2, 3], ksl=[0, 1, 2, 3], hxl=0, hyl=0, l=0, rel=0)
# benchmark.Multipole.track(x, p)
# print type(x)

from pysixtrack import *


particle = {'tau': 1.7366886580440752e-05, 'delta': 0.00028778706824209287, 'y': 0.00067101426313530483, 
'x': 0.00070754573294886313, 'px': -1.8050397692808594e-05, 'py': 7.7125113980128939e-06, 'e0': 65000000000.0}

p=Bunch(**particle)

out = [Multipole(knl=[0, 1, 2, 3], ksl=[0, 1, 2, 3], hxl=0, hyl=0, l=0, rel=0)]

for iii,(el) in enumerate(out):
    print el
    el.track(p)
    for nn in 'x px y py'.split():
      pp=getattr(p,nn)
      print "%-6s %23.16e"%(nn,pp)
    print "\n"



# m=Multipole(knl=[1,2,3],ksl=[2,3,5], hxl=0, hyl=0, l=0, rel=0); 
# p=m.track(Bunch(x=3,y=3)); 
# print p.px,p.py