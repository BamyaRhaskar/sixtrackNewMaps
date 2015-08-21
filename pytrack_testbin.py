from sixtracklib.pysixtrack import *
from sixtracklib.sixdump import SixDump
from sixtracklib.sixinput import SixTrackInput
from sixtracklib.sixbin   import SixBin

from pyoptics import *
from numpy import *

#t=optics.open('med_80_mo_3_s1_4-6_30/twiss.tfs')
#err=optics.open('med_80_mo_3_s1_4-6_30/errors.tfs')

def pprint(p0,p):
  res=0
  out=[]
  for nn in 'x px y py tau delta'.split():
      ss=getattr(p0,nn)
      pp=getattr(p,nn)
      err=sqrt(sum((ss-pp)**2))
      #if abs(ss)>0 and nn!='tau':
      #  err/=abs(ss)
      out.append((nn,err,ss,pp))
      #print "%-6s %23.16e %23.16e %23.16e"%(nn,err,ss,pp)
      res+=err
  return res,out


exampledir='med_80_mo_3_s1_4-6_30'
#exampledir='med_80_bb_2_s1_4-6_30'
#exampledir='med_80_mo_3_s1_0sigma'
s=SixTrackInput(exampledir)
convert={'drift':Drift, 'mult':Multipole, 'cav': Cavity,
         'align':Align,'block':Block}
out,rest=s.expand_struct(convert=convert)


b=SixBin(exampledir)
p=Bunch(**b.get_particle(1,0))
err={}
bench=[]
for  iii,(name,ccc,el) in enumerate(out):
  el.track(p)
  pnew=p.copy()
  p=Bunch(**b.get_particle(1,iii+1))
  #print iii,p.s,el
  res,rrr=pprint(p,pnew)
  err[res]=(iii,name,el,rrr)
  bench.append(err[res])

for kk in bench[:2]:
    iii,name,el,val=kk
    print iii,name,el
    for nn,re,ss,pp in val:
      print "%-6s %23.16e %23.16e %23.16e"%(nn,re,ss,pp)

for kk in sorted(err.keys(),reverse=True)[:10]:
    iii,name,el,val=err[kk]
    print iii,name,el
    for nn,re,ss,pp in val:
      print "%-6s %23.16e %23.16e %23.16e"%(nn,re,ss,pp)


# accumulated error
#b=SixBin(exampledir)
#p=Bunch(**b.get_particle(1,0))
#pnew=p.copy()
#err={}
#bench=[]
#for  iii,(name,ccc,el) in enumerate(out):
#  el.track(pnew)
#  p=Bunch(**b.get_particle(1,iii+1))
#  #print iii,p.s,el
#  res,rrr=pprint(p,pnew)
#  err[res]=(iii,name,el,rrr)
#  bench.append(err[res])
#
#
#figure()
#vs,vn=array([ [(tt[2],tt[3]) for tt in t[3]] for t in bench]).T
#for i,n in enumerate('x px y py tau pt'.split()):
#  plot(vs[i,:]-vn[i,:],label=n)
#
#legend()
