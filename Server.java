package server_sock;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;


public class Server 
{


    public static void main(String[] args) 
    {

try
{
    ServerSocket ser = new ServerSocket (4444);
    Socket sock = ser.accept();

    BufferedReader ed =new BufferedReader (new InputStreamReader(sock.getInputsStream()));
    String tmp = ed.readLine();
    System.out.print("Server:"+tmp);

    PrintStream pr = new PrintStream(sock.getOutputStream());
    String str = "The message delivered succesfully !!"
    pr.println(str);
    }
    catch(Exception ex){}

    }
}
