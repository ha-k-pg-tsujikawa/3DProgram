using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class camera : MonoBehaviour
{
    [SerializeField] Transform Player;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void LateUpdate()
    {
        //transform.position = new Vector3(Player.position.x, Player.position.y + 1.3f, Player.position.z - 3);

        Vector3 vec = Vector3.zero;

        float rad = transform.eulerAngles.y * Mathf.Deg2Rad;

        vec.x = Mathf.Sin(rad);
        vec.z = Mathf.Cos(rad);

        Vector3 target_dir = Player.transform.forward.normalized;

        vec *= -1.0f;

        float distance = 3.0f;
        Vector3 target_vector = target_dir * distance;

        Vector3 new_pos = Player.transform.position - target_vector;

        new_pos.y += 1.1f;
        transform.position = new_pos;

        transform.eulerAngles = Player.transform.eulerAngles;

    }
}
