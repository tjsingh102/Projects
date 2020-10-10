import java.util.StringTokenizer;

public class Project1 {

	public static void main(String[] args) {
		TextFileInput input;
		input = new TextFileInput(args[0]); // taking in the "Project1Input.txt as a TextFileInput in order to read it
											// into a string
		String line;
		line = input.readLine(); // setting line to store the line that is being read from "Project1Input.txt"
		String completeString = "";

		while (line != null) {
			completeString += line + " "; // while loop until line is able to read the entire .txt file
			line = input.readLine(); // storing each line into completeString since readLine() only reads one line at
										// a time
		}
		StringTokenizer tokens;
		tokens = new StringTokenizer(completeString); // creating a string tokenizer which will tokenize completeString
														// which is currently
		String[] totalArray; 							// holding the txt input a string
		totalArray = new String[tokens.countTokens()]; // creating a new array to hold all of the words using count
														// tokens for the size

		for (int i = 0; i < totalArray.length; i++) {
			totalArray[i] = tokens.nextToken(); // for loop that will add each word into a new spot in the array using
												// nextToken() to move through each word

		}
		int validcounter = 0; // creating counters for the other 2 arrays
		int invalidcounter = 0;

		int i = 0;
		while (totalArray.length > i) {
			if (totalArray[i].matches("[a-zA-Z]+")) { // while loop which tests which words contain only letters
				validcounter++;
				i++; // if word is valid then valid counter will be incremented because it is the
						// size for the valid words array
			} else {
				invalidcounter++; // same thing for invalid array
				i++;
			}
		}
		int j = 0;
		int a = 0;
		int b = 0;

		String[] validArray = new String[validcounter];
		String[] invalidArray = new String[invalidcounter];

		while (totalArray.length > j) {
			if (totalArray[j].matches("[a-zA-Z]+")) {
				validArray[a] = totalArray[j];
				a++;
				j++; // adding each valid and invalid word into their separate arrays using the same
						// match method

			} else { // only incrementing positions in each array when matched to avoid empty indexes
				invalidArray[b] = totalArray[j];
				b++;
				j++;
			}
		}
		SelectionSort(validArray); // call to method

		GUI GUI = new GUI();

		for (int xyz = 0; xyz < totalArray.length; xyz++) { // adding each array to the containers from gui
			GUI.insertTotal(totalArray[xyz] + "\n");
		}

		for (int xyz = 0; xyz < validArray.length; xyz++) {
			GUI.insertValid(validArray[xyz] + "\n");
		}

		for (int xyz = 0; xyz < invalidArray.length; xyz++) {
			GUI.insertInvalid(invalidArray[xyz] + "\n");
		}
	}

	public static void SelectionSort(String[] array) {
		for (int i = 0; i < array.length; i++) {
			for (int j = i + 1; j < array.length; j++) { // checking each array index against every other index using
															// compareTo()
				if (array[j].compareTo(array[i]) < 0) {
					String temp = array[i]; // basic swap function
					array[i] = array[j];
					array[j] = temp;
				}
			}
		}
	}
}
