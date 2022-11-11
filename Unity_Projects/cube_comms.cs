using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.IO.Ports;


public class cube_comms : MonoBehaviour
{

    SerialPort serial = new SerialPort("COM4", 115200);
    // public int receivedData;
    public int receivedData;
    public char receivedChar;
    public int receivedInt;
    public int dist = 0;
    public char[] rec = new char[10];

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("Start");
        serial.Open();
        if(serial.IsOpen){
            serial.ReadTimeout = 1;
        }
    }

    // Update is called once per frame
    void Update()
    {   
        if(serial.IsOpen){
            // Data received should an int form 0-255 (1 byte)
            // Normalize by diving by 25.5 to get values from 0 to 10
           
            // receivedData = serial.ReadByte();
            // receivedData = serial.ReadLine();
            receivedData = serial.ReadByte();
            receivedChar = ((char)receivedData);
            receivedInt = receivedChar - '0';
            // serial.Read(rec, )
            // serial.BaseStream.Flush();
            
            // dist = (float)(receivedData / 25.5);
            // Debug.Log("Distance: " + dist);
            
            transform.position = new Vector3(receivedInt, 0, 0);

            dist = (dist + 1) % 255;
        }

        

    }
}
