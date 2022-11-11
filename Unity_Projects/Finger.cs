using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Finger : MonoBehaviour
{
    public Transform j1;
    public Transform j2;
    public Transform j3;
    public float xAng, yAng, zAng;
    // Start is called before the first frame update
    void Start()
    {
    

    }

    // Update is called once per frame
    void Update()
    {
        if(xAng < 45){
            xAng += 0.1F;
        }
        else{
            xAng = 0.0F;
        }
        // Adjust proportions of finger rotation
        j1.eulerAngles = new Vector3(xAng, yAng, zAng) * 1;
        j2.eulerAngles = new Vector3(xAng, yAng, zAng) * 2;
        j3.eulerAngles = new Vector3(xAng, yAng, zAng) * 3;
    }
}
