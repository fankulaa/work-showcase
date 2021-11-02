using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class pressToStartGame : MonoBehaviour
{
    public Text warningText;

    // Start is called before the first frame update
    void Start()
    {
        PauseGame();
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.anyKey)
        {
            ResumeGame();
        }
    }

    void PauseGame()
    {
        Time.timeScale = 0;
    }

    void ResumeGame()
    {
        warningText.gameObject.SetActive(false);
        Time.timeScale = 1;

    }
}
