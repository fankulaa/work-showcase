using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class enemyHealth : MonoBehaviour
{
    public float enemyMaxHealth;
    float currentHealth;
    public GameObject enemyDeathFX;
    public Slider enemyHealthSlider;

    // Start is called before the first frame update
    void Start()
    {
        currentHealth = enemyMaxHealth;
        enemyHealthSlider.maxValue = currentHealth;
        enemyHealthSlider.value = currentHealth;
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void addDamage(float damage)
    {
        enemyHealthSlider.gameObject.SetActive(true);
        currentHealth -= damage;

        enemyHealthSlider.value = currentHealth;
        if (currentHealth <= 0) makeDead();
    }

    void makeDead()
    {
        Destroy(gameObject);
        Instantiate(enemyDeathFX, transform.position, transform.rotation);
    }
}
