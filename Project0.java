import javax.swing.JOptionPane;

public class Project0 {
    public static void main(String[] args) {
        while (true) {
            String input = JOptionPane.showInputDialog("Please enter a sentence: ");
            String stop = "stop";
            if (stop.equalsIgnoreCase(input)) { // checking if the input is stop in whatever uppercase or lowercase
                return;
            } else {
                int uppercases = 0; // variables to store the amount of uppercase and lowercase e's
                int lowercases = 0;

                for (int i = 0; i < input.length(); i++) { // for loop to run through the string
                    if (input.charAt(i) == 'e') // and check for uppercase and lowercase e's and store them in variables
                        lowercases++;
                    if (input.charAt(i) == 'E')
                        uppercases++;
                }
                JOptionPane.showMessageDialog(null,
                        " Number of uppercase e's: " + uppercases + "\n Number of lowercase e's: " + lowercases);
            }
        }
    }
}