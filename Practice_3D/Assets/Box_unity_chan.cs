using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Box_unity_chan : MonoBehaviour
{
    [SerializeField] Transform target;
    [SerializeField] float stopDistance;
    float speed = 5;

    Vector3 pos;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 vec = Vector3.zero;

        float rad = transform.eulerAngles.y * Mathf.Deg2Rad;

        vec.x = Mathf.Sin(rad);
        vec.z = Mathf.Cos(rad);

        Vector3 target_dir = target.transform.forward.normalized;

        vec *= -1.0f;

        float distance = 1.0f;
        Vector3 target_vector = target_dir * distance;

        Vector3 new_pos = target.transform.position - target_vector;

        float Distance = Vector3.Distance(transform.position, target.position);

        //transform.position = new_pos;

        transform.eulerAngles = target.transform.eulerAngles;

        if (Distance > stopDistance)
        {
            pos += (target.position - transform.position) * speed;
            transform.position += pos *= Time.deltaTime;
        }
    }
}
