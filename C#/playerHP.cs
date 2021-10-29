using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class playerHP : MonoBehaviour
{
    public float maxHealth;
    public GameObject deathFX;

    public restartGame theGameManager;

    float currentHealth;

    playerController myPC;

    //HUD Variables
    public Slider healthSlider;
    public Image damageScreen;
    public Text gameOverScreen;

    bool damaged = false;
    Color damagedColor = new Color(0f, 0f, 0f, 0.5f);
    float smoothColor = 5f;

    // Start is called before the first frame update
    void Start()
    {
        currentHealth = maxHealth;
        myPC = GetComponent<playerController>();

        //HUD Initilization
        healthSlider.maxValue = maxHealth;
        healthSlider.value = maxHealth;
    }

    // Update is called once per frame
    void Update()
    {
        if (damaged)
        {
            damageScreen.color = damagedColor;
        }
        else
        {
            damageScreen.color = Color.Lerp(damageScreen.color, Color.clear, smoothColor * Time.deltaTime);
        }
        damaged = false;
    }

    public void addDamage(float damage)
    {
        if (damage<=0) return;
        currentHealth -= damage;

        healthSlider.value = currentHealth;
        damaged = true;

        if (currentHealth <= 0)
        {
            makeDead();
        }
    }
    public void makeDead()
    {
        Instantiate(deathFX, transform.position, transform.rotation);
        Destroy(gameObject);
        damageScreen.color = damagedColor;

        Animator gameOverAnimator = gameOverScreen.GetComponent<Animator>();
        gameOverAnimator.SetTrigger("gameOver");

        theGameManager.restartTheGame();
    }
}
