def func:
    n = raw_input();
    if n%4==0 and n%100!=0:
        print Yes
        return;
    elif n%4==0 and n%100=0:
        if n%400==0:
            print Yes
            return;
        else:
            print False
            return;
print Function call 
func()
