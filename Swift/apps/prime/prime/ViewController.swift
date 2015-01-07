//
//  ViewController.swift
//  prime
//
//  Created by Andy Shi on 12/27/14.
//  Copyright (c) 2014 Andy Shi. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet var result: UILabel!
    @IBOutlet var inputVal: UITextField!
   
    @IBAction func findPrime(sender: AnyObject) {
        if inputVal != nil {
            var num = inputVal.text.toInt()!
            var prime = true
            
            if (num < 3){
                prime=false
            }
            else {
                for (var n = 2; n < num; n++)
                {
                    if num % n == 0
                    {
                        prime = false
                    }
                }
            }
            
            if(prime){
                result.text = "Yep!"
            }
            else{
                result.text = "Nope!"
            }
        }
        else
        {
            result.text = "Input valid number"
        }
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

