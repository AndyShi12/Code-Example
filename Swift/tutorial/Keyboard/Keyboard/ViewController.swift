//
//  ViewController.swift
//  Keyboard
//
//  Created by Andy Shi on 1/1/15.
//  Copyright (c) 2015 Andy Shi. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITextFieldDelegate {

    @IBOutlet var inputText: UITextField!
    @IBOutlet var labelText: UILabel!

    
    
    @IBAction func updateButton(sender: AnyObject) {
        labelText.text = inputText.text
    }
    
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        return true
    }
    
    override func touchesBegan(touches: NSSet, withEvent event: UIEvent) {
        self.view.endEditing(true)
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

