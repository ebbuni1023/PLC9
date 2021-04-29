import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/*

$ == scalar variable identifier
@ == Array identifier
% == HashMap identifier

*/
class Main {
  enum STATE{
    state0, state1, state2, state3, state4, state5, state6,state7, state8, state9, state10,state11,state12,state13, state14, state15, state16,state17;
  }
  public static void main(String[] args) {
    
		try {
      File file = new File("question1.txt");
			Scanner scanner = new Scanner(file);
			while (scanner.hasNext()) {
        String s = scanner.nextLine();
        char[] input = s.trim().toCharArray();
        System.out.println(s);
        System.out.println(isIdentifier(input));
        System.out.println();
			}
			scanner.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	static boolean isOperator(String tkn) 
	{ 
    		if (tkn.equals("+") || tkn.equals("-") || tkn.equals("*") ||  
        	    tkn.equals("/") || tkn.equals(">") ||tkn.equals("<") ||
		    tkn.equals("=") || tkn.equals(">=") ||tkn.equals("<=") ||
		    tkn.equals("!=") || tkn.equals("||")|| tkn.equals("&&") ||
		    tkn.equals("%") || tkn.equals("!") || tkn.equals(".."))  
        		return true; 
    		return false; 
	} 

	static boolean isStringLiteral(String s) 
	{ 
    		char[] str=s.toCharArray();	
		
		int i, len = s.length(); 
		if (len == 0) 
        		return (false);
		if (str[0]=='\"' && str[len-1]=='\"')
			return true;
		return false;
	}
  
  static boolean isNumber(String s)
    {
        for (int i = 0; i < s.length(); i++)
            if (Character.isDigit(s.charAt(i)) == false)
                return false;
 
        return true;
    }
  public static String isIdentifier(char charArr []){
    STATE current = STATE.state0;
    int i = 0;
    int length = charArr.length;
    while(current != STATE.state13 && i <length){
      switch(current){
        case state0:
          if( charArr[i] == '%')
            current = STATE.state1;
          else if(charArr[i] == '@')
            current = STATE.state3;
          else if (charArr[i] == '$')
            current = STATE.state5;
          else if (charArr[i] == '+')
            return "Addition";
          else if (charArr[i] == '=')
            return "Assignment";
          else if (charArr[i] == '-') {
              return "Subtration";
          } else if (charArr[i] == '/') {
              return "Division";
          } else if (charArr[i] == '*') {
            return "Multiplication";
          }
          else if (charArr[i] == '%') {
            return "Modulo Operator";
          } else if (charArr[i] == '&') {
              if (charArr[i+1] == '&') {
                return "Logical AND";
              } else current = STATE.state13;
          } 
          else if (charArr[i] == '|') {
              if (charArr[i+1] == '|') {
                return "Logical OR";
              } else current = STATE.state13;
          } else if (charArr[i] == '!') {
            return "Logical NOT";
          }else if (charArr[i] == '{') {
            return "Open Code Block";
          }
          else if (charArr[i] == '}') {
            return "Close Code Block";
          }
          else if (charArr[i] == '(') {
            return "Open Function Parameter";
          }else if (charArr[i] == ')') {
            return "Close Function Parameter";
          }
          else if (charArr[i] == '[') {
            return "Open Array Index Parameter";
          }else if (charArr[i] == ']') {
            return "Close Array Index Parameter";
          } else if (Character.isDigit(charArr[i])) {
            current = STATE.state14;
          } else if (!Character.isDigit(charArr[i])) {
            current = STATE.state14;
          } 

          i++;
          break;
        case state1:
          if(Character.isLetter(charArr[i])|| charArr[i] == '_'){
            current = STATE.state2;
            i++;
          }
          else 
            current = STATE.state13;
          break;
        case state2:
          if(Character.isLetter(charArr[i]) || Character.isDigit(charArr[i]) || charArr[i] == '_'){
            i++;
          }
          else 
            current = STATE.state13;
          break;
        case state3:
          if(Character.isLetter(charArr[i])|| charArr[i] == '_'){
            current = STATE.state4;
            i++;
          }
          else 
            current = STATE.state13;
          break;
        case state4:
          if(Character.isLetter(charArr[i]) || Character.isDigit(charArr[i]) || charArr[i] == '_'){
            i++;
          }
          else 
            current = STATE.state13;
          break;
        case state5:
          if(Character.isLetter(charArr[i])|| charArr[i] == '_'){
            current = STATE.state6;
            i++;
          }
          else 
            current = STATE.state13;
          break;
        case state6:
          if(Character.isLetter(charArr[i]) || Character.isDigit(charArr[i]) || charArr[i] == '_'){
            i++;
          }else if (charArr[i] == '['){
            current = STATE.state7;
            i++;
          }
          else if (charArr[i] == '{'){
            current = STATE.state9;
            i++;
          }
          else 
            current = STATE.state13;
          break;
        case state7:
          if(Character.isDigit(charArr[i])){
            i++;
          }else if(charArr[i]==']'){
            current = STATE.state8;
            i++;
          }
          else 
            current = STATE.state13;
          break;
        case state8:
          current = STATE.state13;
          break;
        case state9:
          if (charArr[i] == '\''){
            current = STATE.state10;
            i++;
          }
          else 
            current = STATE.state13;
          break;
        case state10:
          if (charArr[i] == '\''){
            current = STATE.state11;
            i++;
          }
          else {
            current = STATE.state10;
            i++;
          }
          break;
        case state11:
          if(charArr[i]=='}'){
            current = STATE.state12;
            i++;
          }
          else 
            current = STATE.state13;
          break;
        case state12:
          current = STATE.state13;
          break;
        case state14:
          if (Character.isDigit(charArr[i]) == false) {
                current = STATE.state16; //
                break; 
            }
        
        current = STATE.state17;
          break;

      }
    }
    if(current == STATE.state2)
      return "HashMap identifier";
    if(current == STATE.state4)
      return "Array identifier";
    if(current == STATE.state6)
      return "Scalar Variable identifier";
    if(current == STATE.state8)
      return "Element of array identifier";
    if(current == STATE.state12)
      return "value from hash identifier";
    if (current == STATE.state17) 
    return "Integer";
    if (current == STATE.state16) 
    return "String";
    else
      return "Invalid identifier";
  }
}