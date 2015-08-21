# import benchmark
# p = Bunch()
# x  = benchmark.Multipole(knl=[0, 1, 2, 3], ksl=[0, 1, 2, 3], hxl=0, hyl=0, l=0, rel=0)
# benchmark.Multipole.track(x, p)
# print type(x)

from pysixtrack import *

particle = {'tau': 3, 'delta': 3, 'y': 3, 
'x': 3, 'px': 3, 'py': 3, 'e0': 3}

p=Bunch(**particle)

out = [Multipole(knl=[1,6,3],ksl=[2,3,5], hxl=0, hyl=0, l=1, rel=0)]

for iii,(el) in enumerate(out):
    print el
    el.track(p)
    for nn in 'x px y py pt'.split():
      pp=getattr(p,nn)
      print "%-6s %23.16e"%(nn,pp)
    print "\n"


# m=Multipole(knl=[1,2,3],ksl=[2,3,5], hxl=0, hyl=0, l=0, rel=0); 

# p=m.track(Bunch(x=3,y=3)); 

# print p.px,p.py