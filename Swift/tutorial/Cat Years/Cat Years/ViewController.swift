//
//  ViewController.swift
//  Cat Years
//
//  Created by Andy Shi on 12/25/14.
//  Copyright (c) 2014 Andy Shi. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet var answer: UILabel!
    @IBOutlet var inputAge: UITextField!
    
    @IBAction func findAge(sender: AnyObject) {
        var enteredAge = inputAge.text.toInt()
        if (enteredAge != nil)
        {
            var catYears = enteredAge! * 7
            answer.text = "Your cat is \(catYears)"
        }
        else{
            answer.text = "Input age"
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

