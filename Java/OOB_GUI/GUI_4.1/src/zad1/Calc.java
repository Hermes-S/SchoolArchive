/**
 *
 *  @author Prystupa Piotr S12463
 *
 */

package zad1;



import java.math.BigDecimal;
import java.util.Scanner;


public class Calc {

	public String doCalc(String string) {

		String option = "";
		try {
			
			Scanner sc = new Scanner (string);
			
			BigDecimal one = new BigDecimal(sc.next());
			option = sc.next();
			BigDecimal two = new BigDecimal(sc.next());
			sc.close();
			Imagination.setImaginaryFriendz(one, two);

		}
		catch (Exception ex){
			return "Invalid command to calc";
		}

		return Imagination.getResult(option);
	}
}    
