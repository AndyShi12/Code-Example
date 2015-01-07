//
//  ViewController.swift
//  Persistant Storage
//
//  Created by Andy Shi on 1/1/15.
//  Copyright (c) 2015 Andy Shi. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
       // var exampleString = "Test"
       // println(exampleString)
        
        // use persistant storage
        //NSUserDefaults.standardUserDefaults().setObject("Rob", forKey: "myName")
        // sync data
        //NSUserDefaults.standardUserDefaults().synchronize()
        // access
        println(NSUserDefaults.standardUserDefaults().objectForKey("myName"))
        
        
        
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

