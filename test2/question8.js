var x = 1, 
    y = 3,
    z = 5;
    sub1();
function sub1(){
    var a = 7, 
        y = 9,
        z = 11;
    console.log("first " , a, y, z + "");
    sub2()
}
    function sub2(){
        var a = 13,
            b = 15,
            z = 17;
        console.log("global " , a, b, z + "");
        return sub3()
    }
function sub3(){
    var a = 19,
        x = 21,
        w = 23;
        console.log("local " , a, x, w, "");
}