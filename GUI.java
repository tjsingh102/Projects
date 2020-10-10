import javax.swing.*;
import java.awt.*;

public class GUI{
    private JFrame frame;
    private Container cPane;
    private TextArea TotalWords, invalidWords, validWords;
    
    

    public GUI () {
        TotalWords = new TextArea();
        validWords = new TextArea(); 	//creating 3 new text areas, one for each type of array.
        invalidWords = new TextArea();
        frame = new JFrame();        // creating and setting the size of the window.
        frame.setSize(800,400);
        frame.setTitle("Project 1 - Tejinderpal Singh 212 LAB 11F");
        TotalWords.setEditable(false);
        validWords.setEditable(false); // not allowing the text to be edited.
        invalidWords.setEditable(false);
        
        frame.setLayout(new GridLayout(1,3));
        cPane = frame.getContentPane();       // creating 1 row and 3 columns 
        cPane.add(TotalWords);				// adding the text areas to 3 different containers 	
        cPane.add(invalidWords);
        cPane.add(validWords);
        
        

        
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        
            }

        public void insertTotal(String str) { // adding this to the end of "Project1.java" in order to add each string to GUI
            TotalWords.append(str);
        }
        public void insertValid(String str) {
            validWords.append(str);
        }
    
        public void insertInvalid(String str) {
            invalidWords.append(str);
        }
 
    }
