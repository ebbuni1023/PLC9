x = 1
y = 3
z = 5

# nested first deep
def sub1():
    a = 7
    y = 9
    z = 11
    print("First", a,y,z)
    # nested second deep
    def sub2():
        global x
        a= 13
        x = 15
        w = 17
 
        print("global", a,x,w)

        # nested third deep
        def sub3():
            nonlocal a
            a = 19
            b = 21
            z = 23
            print("local", a,b,z)
        sub3()
    sub2()
sub1()
