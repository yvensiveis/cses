i=input;j=int;t=j(i())
while t:
    a,b,c,d,e,f=map(j,i().split())
    k=(f-b)*(c-a)-(e-a)*(d-b)
    print("LEFT"if k>0 else"RIGHT"if k else"TOUCH")
    t-=1