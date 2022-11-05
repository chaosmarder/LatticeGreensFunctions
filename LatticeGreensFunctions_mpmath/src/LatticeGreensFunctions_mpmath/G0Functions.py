from numpy import zeros,sqrt
from scipy import *
from scipy.special import ellipk,ellipe
from scipy.optimize import root
from mpmath import mp
from mpmath import mpf
gamma=0.577215664901

def G0_00(e):
    B=4.0
    z=e+B
    l=B/z
    k=1.0/l
    k2=k*k
    kp2=1.0-k2
    Kl=ellipk(kp2)
    if z>=0:
        r=(2.0/pi/B)*ellipk(k2)
        """
        Note that scipy defines the elliptic function with the square of the argument
        in comparision with Economou
        """
    else:
        r=-(2.0/pi/B)*ellipk(k2)
    i=(2.0/pi/B)*Kl
    return (r+1j*i) 

def G0_00_f(f):
    if f>30:
        r=(1./(4.*pi))*(log(32.)+f)
        i=.25
    else:
        e=-exp(-f)
        B=4.0
        z=e+B
        l=B/z
        k=1.0/l
        k2=k*k
        kp2=1.0-k2
        Kl=ellipk(kp2)
        if z>=0:
            r=(2.0/pi/B)*ellipk(k2)
            """
            Note that scipy defines the elliptic function with the square of the argument
            in comparision with Economou
            """
        else:
            r=-(2.0/pi/B)*ellipk(k2)
        i=(2.0/pi/B)*Kl
    return (r+1j*i)


def G0_11_i(e):
    B=4.0
    z=e+B
    l=B/z
    l2=l*l
    k=1.0/l
    kp=sqrt(1.0-k**2)
    kp2=1.0-k**2
    Kl=k*ellipk(kp2)
    El=1/k*(-ellipe(kp2)+k**2*ellipk(kp2)) #Way scipy defines integrals
    i=2.0/(pi*z)*((2.0/l**2-1.0)*Kl-2.0/l**2*El)
    #r=2.0/(pi*abs(z))*((2.0/l**2-1.0)*ellipk(l2)-2.0/l**2*ellipe(l2))
    return i

def G0_11_r(e):
    B=4.0
    z=e+B
    l=B/z
    l2=l*l
    k=1.0/l
    kp=sqrt(1.0-k**2)
    kp2=1.0-k**2
    #Kl=k*ellipk(kp2)
    #El=1/k*(-ellipe(kp2)+k**2*ellipk(kp2)) #Way scipy defines integrals
    #i=2.0/(pi*z)*((2.0/l**2-1.0)*Kl-2.0/l**2*El)
    r=2.0/(pi*abs(z))*((2.0/l**2-1.0)*ellipk(l2)-2.0/l**2*ellipe(l2))
    return r

def G0_11(e):
    B=4.0
    z=e+B
    l=B/z
    k=1.0/l
    k2=k*k
    kp=sqrt(1.0-k**2)
    kp2=1.0-k**2
    Ki=k*ellipk(kp2)
    Kr=k*ellipk(k2)
    Ei=1/k*(-ellipe(kp2)+k**2*ellipk(kp2)) #Way scipy defines integrals
    Er=1/k*(ellipe(k2)-kp**2*ellipk(k2)) #Way scipy defines integrals
    i=2.0/(pi*z)*((2.0/l**2-1.0)*Ki-2.0/l**2*Ei)
    if z>0:
        r=2.0/(pi*z)*((2.0/l**2-1.0)*Kr-2.0/l**2*Er)
    else:
        r=-2.0/(pi*z)*((2.0/l**2-1.0)*Kr-2.0/l**2*Er)
    return r+1j*i

def G0_11_f(f):
    if f>20:
        r=(1./(4.*pi))*(log(0.5861)+f) #FIX THIS!!!
        i=.25
    else:
        e=-exp(-f)
        B=4.0
        z=e+B
        l=B/z
        k=1.0/l
        k2=k*k
        kp=sqrt(1.0-k**2)
        kp2=1.0-k**2
        Ki=k*ellipk(kp2)
        Kr=k*ellipk(k2)
        Ei=1/k*(-ellipe(kp2)+k**2*ellipk(kp2)) #Way scipy defines integrals
        Er=1/k*(ellipe(k2)-kp**2*ellipk(k2)) #Way scipy defines integrals

        i=2.0/(pi*z)*((2.0/l**2-1.0)*Ki-2.0/l**2*Ei)
        if z>0:
            r=2.0/(pi*z)*((2.0/l**2-1.0)*Kr-2.0/l**2*Er)
        else:
            r=-2.0/(pi*z)*((2.0/l**2-1.0)*Kr-2.0/l**2*Er)
    return r+1j*i



def G0_00_f_mp(f):
    if f>5000: #FIX!!!
        r=(mpf(1)/(mpf(4)*mp.pi))*(mp.log(32)+f)
        i=mpf(1)/mpf(4)
    else:
        e=-mp.exp(-f)
        B=mpf(4)
        z=e+B
        l=B/z
        k=mpf(1)/l
        k2=k*k
        kp2=mpf(1)-k2
        Kl=mp.ellipk(kp2)
        if z>=0:
            r=(mpf(2)/mp.pi/B)*mp.ellipk(k2)
            """
            Note that scipy defines the elliptic function with the square of the argument
            in comparision with Economou
            """
        else:
            r=-(mpf(2)/mp.pi/B)*mp.ellipk(k2)
        i=(mpf(2)/mp.pi/B)*Kl
    return (r+1j*i)

def G0_00_c_mp(e):
    B=mpf(4)
    z=e+B
    l=B/z
    k=mpf(1)/l
    k2=k*k
    kp2=mpf(1)-k2
    K=mpf(2)/(mp.pi*z)*mp.ellipk(l*l)
    return K

def G0_11_c_mp(e):
    B=mpf(4)
    z=e+B
    l=B/z
    l2=l*l
    k=mpf(1)/l
    k2=k*k
    kp2=mpf(1)-k2
    K=mpf(2)/(mp.pi*z)*((mpf(2)*k2-1)*mp.ellipk(l2)-mpf(2)*k2*mp.ellipe(l2))
    return K

def G0_11_f_mp(f):
    #if f>5000:
    #    r=(mpf(1)/(mpf(4)*mp.pi))*(mp.log(0.5861)+f) #FIX THIS!!!
    #    i=1/mpf(4)
    #else:
    e=-mp.exp(-f)
    B=mpf(4)
    z=e+B
    l=B/z
    k=mpf(1)/l
    k2=k*k
    kp=sqrt(mpf(1)-k**2)
    kp2=mpf(1)-k**2
    Ki=k*mp.ellipk(kp2)
    Kr=k*mp.ellipk(k2)

    Ei=mpf(1)/k*(-mp.ellipe(kp2)+k**2*mp.ellipk(kp2)) #Way scipy defines integrals
    Er=mpf(1)/k*(mp.ellipe(k2)-kp**2*mp.ellipk(k2)) #Way scipy defines integrals
    i=mpf(2)/(mp.pi*z)*((mpf(2)/l**2-mpf(1))*Ki-mpf(2)/l**2*Ei)
    if z>0:
        r=mpf(2)/(mp.pi*z)*((mpf(2)/l**2-mpf(1))*Kr-mpf(2)/l**2*Er)
    else:
        r=-mpf(2)/(mp.pi*z)*((mpf(2)/l**2-mpf(1))*Kr-mpf(2)/l**2*Er)
    return r+1j*i

def dG_large_m_near_0(e,x,y):
    return -1/pi*(log(2)+gamma/2.0)-(1/(2*pi))*log(sqrt(x**2+y**2)/2.0)

def G_large_m_near_0(e,x,y):
    return dG_large_m_near_0(e,x,y)+G0_00(e)


def G0_10(e):
    return (G0_00(e)*(e+4.0)-1.0)/4.0
def G0_20(e):
    return G0_10(e)*(e+4.0)-0.0-G0_00(e)-2*G0_11(e)

def g0f(e,ymax):
    g0=zeros(ymax+1,'complex')
    g0[0]=G0_00(e)
    g0[1]=G0_11(e)
    y=1
    while (y<ymax):
       g0[y+1]= 4.0*y/(2.0*y+1.0)*((e+4.0)**2/8.0-1.0)*g0[y]-(2.0*y-1.0)/(2.0*y+1.0)*g0[y-1]
       y=y+1
    return g0

def g1f(e,ymax,g0):
    g1=zeros(ymax+1,'complex')
    g1[0]=((e+4.0)*g0[0]-1.0)/4.0
    y=1
    while y<ymax+1:
        g1[y]=((e+4.0)*g0[y]-2.0*g1[y-1])/2.0
        y=y+1
    return g1

def gsf(e,ymax):
    g=zeros([ymax+1,ymax+1],'complex')
    g0=g0f(e,ymax)
    g1=g1f(e,ymax,g0)
    g[0,:]=g0[:]
    g[1,:]=g1[:]
    G=zeros([ymax+1,ymax+1],'complex')
    for y in range(ymax+1):
        G[y,y]=g0[y]
    for y in range(ymax):
        G[y+1,y]=g1[y]
    for s in range(1,ymax):
        g[s+1,0]=-g[s-1,1]-g[s-1,0]-g[s-1,1]+(e+4.0)*g[s,0]
        G[s+1,0]=g[s+1,0]
        for y in range(1,ymax-s):
            g[s+1,y]=-g[s+1,y-1]-g[s-1,y]-g[s-1,y+1]+(e+4.0)*g[s,y]
            G[y+s+1,y]=g[s+1,y]
    return G

def g0f_f(f,ymax):
    e=-exp(-f)
    g0=zeros(ymax+1,'complex')
    g0[0]=G0_00_f(f)
    g0[1]=G0_11_f(f)
    y=1
    while (y<ymax):
       g0[y+1]= 4.0*y/(2.0*y+1.0)*((e+4.0)**2/8.0-1.0)*g0[y]-(2.0*y-1.0)/(2.0*y+1.0)*g0[y-1]
       y=y+1
    return g0

def g1f_f(f,ymax,g0):
    e=-exp(-f)
    g1=zeros(ymax+1,'complex')
    g1[0]=((e+4.0)*g0[0]-1.0)/4.0
    y=1
    while y<ymax+1:
        g1[y]=((e+4.0)*g0[y]-2.0*g1[y-1])/2.0
        y=y+1
    return g1

def gsf_f(f,ymax):
    e=-exp(-f)
    g=zeros([ymax+1,ymax+1],'complex')
    g0=g0f_f(f,ymax)
    g1=g1f_f(f,ymax,g0)
    g[0,:]=g0[:]
    g[1,:]=g1[:]
    G=zeros([ymax+1,ymax+1],'complex')
    for y in range(ymax+1):
        G[y,y]=g0[y]
    for y in range(ymax):
        G[y+1,y]=g1[y]
    for s in range(1,ymax):
        g[s+1,0]=-g[s-1,0]-2*g[s-1,1]+(e+4.0)*g[s,0]
        G[s+1,0]=g[s+1,0]
        for y in range(1,ymax-s):
            g[s+1,y]=-g[s+1,y-1]-g[s-1,y]-g[s-1,y+1]+(e+4.0)*g[s,y]
            G[y+s+1,y]=g[s+1,y]
    return G

def g0f_f_mp(f,ymax):
    e=-mp.exp(-f)
    g0=zeros(ymax+1,'object')
    g0[0]=G0_00_f_mp(f)
    g0[1]=G0_11_f_mp(f)
    y=1
    while (y<ymax):
       g0[y+1]= mpf(4)*y/(mpf(2)*y+mpf(1))*((e+mpf(4))**2/mpf(8)-mpf(1))*g0[y]-(mpf(2)*y-mpf(1))/(mpf(2)*y+mpf(1))*g0[y-1]
       y=y+1
    return g0

def g1f_f_mp(f,ymax,g0):
    e=-mp.exp(-f)
    g1=zeros(ymax+1,'object')
    g1[0]=((e+mpf(4))*g0[0]-mpf(1))/mpf(4)
    y=1
    while y<ymax+1:
        g1[y]=((e+mpf(4))*g0[y]-mpf(2)*g1[y-1])/mpf(2)
        y=y+1
    return g1

def gsf_f_mp(f,ymax,ReturnComplex=True):
    e=-mp.exp(-f)
    g=zeros([ymax+1,ymax+1],'object')
    g0=g0f_f_mp(f,ymax)
    g1=g1f_f_mp(f,ymax,g0)
    g[0,:]=g0[:]
    g[1,:]=g1[:]
    if ReturnComplex==True:
        G=zeros([ymax+1,ymax+1],'complex')
    else:
        G=zeros([ymax+1,ymax+1],'object')
    for y in range(ymax+1):
        G[y,y]=g0[y]
    for y in range(ymax):
        G[y+1,y]=g1[y]
    for s in range(1,ymax):
        g[s+1,0]=(e+mpf(4))*g[s,0]-mpf(2)*g[s-1,1]-g[s-1,0]
        """
        print '*** computed',s+1,0,g[s+1,0], ' from'
        print s,1,g[s,1]
        print s-1,0,g[s-1,0]
        print s,0,e+mpf(4),g[s,0]
        """
        G[s+1,0]=g[s+1,0]
        for y in range(1,ymax-s):
            g[s+1,y]=-g[s+1,y-1]-g[s-1,y]-g[s-1,y+1]+(e+mpf(4))*g[s,y]
            """
            print '*** computed',s+1,y,g[s+1,y], ' from'
            print s+1,y-1,g[s+1,y-1]
            print s-1,y,g[s-1,y]
            print s-1,y+1,g[s-1,y+1]
            print s,y,e+mpf(4),g[s,y]
            """
            G[y+s+1,y]=g[s+1,y]
    return G

def g0f_mp(e,ymax):
    g0=zeros(ymax+1,'object')
    g0[0]=G0_00_c_mp(e)
    g0[1]=G0_11_c_mp(e)
    y=1
    while (y<ymax):
       g0[y+1]= mpf(4)*y/(mpf(2)*y+mpf(1))*((e+mpf(4))**2/mpf(8)-mpf(1))*g0[y]-(mpf(2)*y-mpf(1))/(mpf(2)*y+mpf(1))*g0[y-1]
       y=y+1
    return g0

def g1f_mp(e,ymax,g0):
    g1=zeros(ymax+1,'object')
    g1[0]=((e+mpf(4))*g0[0]-mpf(1))/mpf(4)
    y=1
    while y<ymax+1:
        g1[y]=((e+mpf(4))*g0[y]-mpf(2)*g1[y-1])/mpf(2)
        y=y+1
    return g1

def gsf_mp(e,ymax):
    g=zeros([ymax+1,ymax+1],'object')
    g0=g0f_mp(e,ymax)
    g1=g1f_mp(e,ymax,g0)
    g[0,:]=g0[:]
    g[1,:]=g1[:]
    G=zeros([ymax+1,ymax+1],'complex')
    for y in range(ymax+1):
        G[y,y]=g0[y]
    for y in range(ymax):
        G[y+1,y]=g1[y]
    for s in range(1,ymax):
        g[s+1,0]=(e+mpf(4))*g[s,0]-mpf(2)*g[s-1,1]-g[s-1,0]
        G[s+1,0]=g[s+1,0]
        for y in range(1,ymax-s):
            g[s+1,y]=-g[s+1,y-1]-g[s-1,y]-g[s-1,y+1]+(e+mpf(4))*g[s,y]
            G[y+s+1,y]=g[s+1,y]
    return G



