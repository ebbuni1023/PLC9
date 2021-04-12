public class TestProgram {
    public static void main (String [] args){
        // scope of the variable i and x
        int i;
        int x;
        // for loop
        for (i = 0; i < 10; i++)
        {
            x += i;
        } 
        // a variable is visible after the body of the for statement       
        System.out.println(x);
    }
}
