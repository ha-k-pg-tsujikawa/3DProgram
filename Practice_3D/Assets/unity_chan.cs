using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class unity_chan : MonoBehaviour
{
    float speed = 0.05f;
    float rote = 180.0f;

    // Update is called once per frame
    void Update()
    {

        if (Input.GetKey(KeyCode.UpArrow))
        {
            Vector3 Speed = Vector3.zero;

            float rad = transform.eulerAngles.y * Mathf.Deg2Rad;

            Speed.x = Mathf.Sin(rad);
            Speed.z = Mathf.Cos(rad);

            Speed *= Time.deltaTime * 3.0f;

            transform.Translate(Speed.x, 0.0f, Speed.z, Space.World);
        }
        else if (Input.GetKey(KeyCode.DownArrow))
        {
            transform.Translate(0.0f, 0.0f, -speed);
        }

        if (Input.GetKey(KeyCode.RightArrow))
        {
            transform.Rotate(0.0f, rote * Time.deltaTime, 0.0f);
        }
        else if (Input.GetKey(KeyCode.LeftArrow))
        {
            transform.Rotate(0.0f, -rote * Time.deltaTime, 0.0f);
        }
    }
}
