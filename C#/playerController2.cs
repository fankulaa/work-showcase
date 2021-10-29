using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playerController : MonoBehaviour
{

    //movement variables
    public float maxSpeed;

    //jumping variables
    public float maxJump;
    public LayerMask groundLayer;
    public Transform groundCheck;
    public float jumpForce = 0f;
    public float goDownForce = 0f;

    bool grounded = false;
    float groundCheckRadius = 0.2f;
    bool canDoubleJump = true;
    bool stomping = false;


    Rigidbody2D myRB;
    Animator myAnim;
    bool facingRight;

    //for shooting
    public Transform gun;
    public GameObject rocket;
    public float fireRate = 0.5f;
    float nextFire = 0f;

    // Start is called before the first frame update
    void Start()
    {
        myRB = GetComponent<Rigidbody2D>();
        myAnim = GetComponent<Animator>();

        facingRight = true;
    }

    // Update is called once per frame
    private void Update()
    {
        //player shooting
        if (Input.GetAxisRaw("Fire1") > 0) fireRocket();

        //jumping
        if (grounded)
        {
            canDoubleJump = true;
            myAnim.SetBool("canDoubleJump", canDoubleJump);
            stomping = false;
            myAnim.SetBool("stomping", stomping);
        }
        //double jump
        //  (Input.GetAxis("Jump") > 1)       LUZO TIK DEL SITO SUDO!!!!! 3h WASTED!
        if (Input.GetKeyDown(KeyCode.Space))
        {
            if (grounded)
            {
                myAnim.SetBool("isGrounded", grounded);
                Jump();
            }
            else if(canDoubleJump)
            {
                canDoubleJump = false;
                Jump();
                myAnim.SetBool("canDoubleJump", canDoubleJump);
            }
        }
    }

    //FixedUpdate can run once, zero, or several times per frame, 
    //depending on how many physics frames per second are set in the time settings, and how fast/slow the framerate
    void FixedUpdate()
    {
        //check if we are grounded, if no we are falling
        grounded = Physics2D.OverlapCircle(groundCheck.position, groundCheckRadius, groundLayer);
        myAnim.SetBool("isGrounded", grounded); 

        myAnim.SetFloat("verticalSpeed", myRB.velocity.y);

        float move = Input.GetAxis("Horizontal");
        myAnim.SetFloat("speed", Mathf.Abs(move));

        myRB.velocity = new Vector2(move * maxSpeed, myRB.velocity.y);

        if (move > 0 && !facingRight)
        {
            flip();
        }
        else if (move < 0 && facingRight)
        {
            flip();
        }

        //get down faster if u press DOWN while falling
        if (myRB.velocity.y < -5 && Input.GetAxis("Vertical") < 0)
        {
            stomping = true;
            myAnim.SetBool("stomping", stomping);
            //dosent work
            myRB.velocity = Vector2.up * (goDownForce*-1);
        }
        //jump trought platforms
        if (myRB.velocity.y > 10)
        {
            myRB.GetComponent<CircleCollider2D>().enabled = false;
            myRB.GetComponent<BoxCollider2D>().enabled = false;
        }
        else
        {
            myRB.GetComponent<CircleCollider2D>().enabled = true;
            myRB.GetComponent<BoxCollider2D>().enabled = true;
        }
    }
    void flip()
    {
        facingRight = !facingRight;
        Vector3 theScale = transform.localScale;
        theScale.x *= -1;
        transform.localScale = theScale;
    }
    void Jump()
    {
        myRB.velocity = Vector2.up * jumpForce;
    }
    void fireRocket()
    {
        if(Time.time > nextFire)
        {
            nextFire = Time.time + fireRate;
            if (facingRight)
            {
                Instantiate(rocket, gun.position, Quaternion.Euler(new Vector3(0,0,0)));
            }
            else if (!facingRight)
            {
                Instantiate(rocket, gun.position, Quaternion.Euler(new Vector3(0, 0, 180f)));
            }
        }
    }
}
