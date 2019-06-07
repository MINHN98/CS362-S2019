import junit.framework.TestCase;
import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;

import static org.junit.Assert.assertEquals;


class test{
    
    ArrayList<String> urls = new ArrayList<String>(); //stores urls
    ArrayList<String> expected = new ArrayList<String>(); //stores expected value of urls
    String fileName;
    int counter = 0;

    public test(){
        fileName = "urls.txt";
    }

    public test(String s){
        fileName = s;
    }


    public void readUrls(){
        File file = null;
        String temp;
        try {
            file = new File("urls.txt");
            Scanner sc = new Scanner(file);

            while(sc.hasNext()){

                temp = sc.next();
                expected.add(temp);

                temp = sc.next();
                urls.add(temp);


            }
        }
        catch(IOException e){
            System.out.print("File IO error");
        }

    }

    public void printUrls(){
        for(int i = 0; i < urls.size(); i++){
            System.out.print(expected.get(i) + "   ");
            System.out.println(urls.get(i));
        }
    }

    public void runTests(){
        long options = UrlValidator.ALLOW_2_SLASHES + UrlValidator.ALLOW_ALL_SCHEMES + UrlValidator.NO_FRAGMENTS;
        UrlValidator validator = new UrlValidator(options);

        for(int i = 0; i < urls.size(); i++){
            counter++;
            assertEquals(detExpected(expected.get(i)), validator.isValid( urls.get(i) ));
        }
    }

    private boolean detExpected(String s){
        s = s.toLowerCase();

        if(s.equals("true")){
            return true;
        }

        return false;
    }

}

class unitTests
{

    public static void main(String[] args)
    {
        test unitTests = new test();

        System.out.print("Filename: ");
        System.out.println(unitTests.fileName);

        unitTests.readUrls();
        //unitTests.printUrls(); //uncomment to print out contents of urls file

        unitTests.runTests();



    }
}
