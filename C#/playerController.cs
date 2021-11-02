using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class playerController : MonoBehaviour
{
    Rigidbody2D myRB;

    //movement
    public float maxSpeed;
    float speed;
    public float rotationSmooth;


    //nitroUI
    public Slider nitroSlider;
    //nitro
    public float maxNitro;
    float currentNitro;
    public float nitroRegeneration;
    public float nitroConsumtion;
    public float nitroCooldown;
    float nitroUseTimer = 0f;
    bool usingNitro;
    public float nitroSpeedMultiplier;
    public SpriteRenderer nitroSprite;



    //scoreUI
    public Text scoreText;
    //score
    int score = 0;
    public float scoreCooldown;
    float nextScore = 0f;

    //timerUI
    public Text timerText;
    //timer
    float timer;
    float timerSec;
    int timerMin;

    //checkpoints
    int checkpointProgress;
    public int checkpointCount=18;
    public Text wrongWay;

    //laps
    int laps;
    string lap1;
    string lap2;
    string lap3;


    // Start is called before the first frame update
    void Start()
    {
        myRB = GetComponent<Rigidbody2D>();

        //movement
        speed = maxSpeed;

        //nitro
        nitroSlider.maxValue = maxNitro;
        nitroSlider.value = maxNitro;
        currentNitro = maxNitro;
    }


    // Update is called once per frame
    void Update()
    {
        //movement+rotation
        float horizontalInput = Input.GetAxis("Horizontal");
        float verticalInput = Input.GetAxis("Vertical");
        Vector2 movementDirection = new Vector2(horizontalInput, verticalInput);
        if (movementDirection != Vector2.zero)
        {
            Quaternion target = Quaternion.LookRotation(Vector3.forward, movementDirection);
            transform.rotation = Quaternion.RotateTowards(transform.rotation, target, Time.deltaTime * rotationSmooth);

            //constant movement
            myRB.AddForce(new Vector2(myRB.GetComponentInChildren<CircleCollider2D>().transform.position.x - myRB.transform.position.x, myRB.GetComponentInChildren<CircleCollider2D>().transform.position.y - myRB.transform.position.y) * speed);
        }
        else
        {
            //constant movement
            myRB.AddForce(new Vector2(myRB.GetComponentInChildren<CircleCollider2D>().transform.position.x - myRB.transform.position.x, myRB.GetComponentInChildren<CircleCollider2D>().transform.position.y - myRB.transform.position.y) * speed);
        }

        //Nitro
        if ((Input.GetKey("joystick button 0") || Input.GetKey("space")) && !usingNitro && (currentNitro - nitroConsumtion) > 0 && Time.time > nitroUseTimer)
        {
            speed = speed * nitroSpeedMultiplier;
            usingNitro = true;
            currentNitro -= nitroConsumtion; //should be made with time.time

            nitroSlider.value = currentNitro;
            nitroSprite.gameObject.SetActive(true);
        }
        else
        {
            usingNitro = false;
            speed = maxSpeed;
            nitroSprite.gameObject.SetActive(false);
            nitroSlider.value = currentNitro;
        }

        if ((currentNitro - nitroConsumtion) < maxNitro / ((maxNitro / 100) * 2))
        {
            nitroUseTimer = Time.time + nitroCooldown;
        }

        if (!usingNitro)
        {


            if (currentNitro < maxNitro)
            {
                currentNitro += nitroRegeneration;
            }
            else if (currentNitro >= maxNitro)
            {
                currentNitro = maxNitro;
            }
            nitroSlider.value = currentNitro;
        }


        //timer
        timer = Time.time;
        timerMin = (int)timer / 60;
        timerSec = timer - (timerMin * 60);
        if (timerSec < 10)
        {
            timerText.text = "Timer: " + timerMin + ":0" + timerSec.ToString("F2");
        }
        else
        {
            timerText.text = "Timer: " + timerMin + ":" + timerSec.ToString("F2");
        }

        //score + laps
        score++;
        scoreText.text = "Score: " + score.ToString() + System.Environment.NewLine +
        "Lap1: " + lap1 + System.Environment.NewLine +
        "Lap2: " + lap2 + System.Environment.NewLine +
        "Lap3: " + lap3;
    }


    //FixedUpdate can run once, zero, or several times per frame, 
    //depending on how many physics frames per second are set in the time settings, and how fast/slow the framerate is.
    private void FixedUpdate()
    {

    }


    private void OnTriggerEnter2D(Collider2D collision)
    {
        //score
        if (collision.gameObject.name == "startingLine" && Time.time > nextScore && checkpointProgress == checkpointCount)
        {
            nextScore = Time.time + scoreCooldown;
            score += 100000;
            checkpointProgress = 0;
            laps++;
            if (laps == 1 && timerSec < 10)
            {
                lap1 = timerMin + ":0" + timerSec.ToString("F2");
            }
            else if (laps == 1 && timerSec > 10)
            {
                lap1 = timerMin + ":" + timerSec.ToString("F2");
            }
            else if (laps == 2 && timerSec < 10)
            {
                lap2 = timerMin + ":0" + timerSec.ToString("F2");
            }
            else if (laps == 2 && timerSec > 10)
            {
                lap2 = timerMin + ":" + timerSec.ToString("F2");
            }
            else if (laps == 3 && timerSec < 10)
            {
                lap3 = timerMin + ":0" + timerSec.ToString("F2");
            }
            else if (laps == 3 && timerSec > 10)
            {
                lap3 = timerMin + ":" + timerSec.ToString("F2");
            }
        }
        //score punishment
        if (collision.gameObject.layer == LayerMask.NameToLayer("Score-"))
        {
            score -= 500;
        }


        //checkpoints
        if (collision.gameObject.name == "checkpoint" + (checkpointProgress + 1).ToString())
        {
            checkpointProgress++;
            wrongWay.gameObject.SetActive(false);
        }
        if (collision.gameObject.name == "checkpoint" + (checkpointProgress - 1).ToString() || ((checkpointProgress == 0 || checkpointProgress == 1) && collision.gameObject.name == "checkpoint" + checkpointCount.ToString()))
        {
            wrongWay.gameObject.SetActive(true);
        }
        if (collision.gameObject.name == "checkpoint" + checkpointProgress)
        {
            wrongWay.gameObject.SetActive(false);
        }


        //nitro fill up
        if(collision.gameObject.name == "nitro++")
        {
            currentNitro = maxNitro;
            nitroUseTimer = Time.time;
        }
    }
}