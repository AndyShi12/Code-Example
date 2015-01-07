//
//  ViewController.swift
//  How Many
//
//  Created by Andy Shi on 12/27/14.
//  Copyright (c) 2014 Andy Shi. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet var inputNum: UITextField!
    @IBOutlet var result: UILabel!
    @IBAction func guessAction(sender: AnyObject) {
        var randomNumber = arc4random_uniform(5)
        
        var guessedInt = inputNum.text.toInt()
        if guessedInt != nil {
            if Int(randomNumber) == guessedInt {
                result.text = "Correct!"
            }
            else
            {
                result.text = "Nope"
            }

        }
        else
        {
            result.text = "input num"
        }
        //println(inputNum.text)
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

