import java.io.BufferedReader;
import java.io.FileWriter;

public class hello{
    public static void main(String[] args){
        System.out.println("Hello, World!");
    }

    try{
        file.createNewFile();
        FileReader fr = new FileReader(file);
        FileWriter fw = new FileWriter(file);

        BufferedReader br = new BufferedReader(fr);
        BufferedWriter bw = new BufferedWriter(fw);

        Scanner sc = new Scanner(file);

        br.close();
        bw.close();
        

    }

}