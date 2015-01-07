//
//  ViewController.swift
//  navBar
//
//  Created by Andy Shi on 12/28/14.
//  Copyright (c) 2014 Andy Shi. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet var time: UILabel!
    var count = 0
    var timer = NSTimer()
    
    @IBAction func startTime(sender: AnyObject) {
        timer = NSTimer.scheduledTimerWithTimeInterval(1, target: self, selector: Selector("result"), userInfo: nil, repeats: true)
    }
    
    @IBAction func pauseTime(sender: AnyObject) {
        timer.invalidate()
    }
    
    @IBAction func resetTime(sender: AnyObject) {
        timer.invalidate()
        count = 0
        time.text = "0"
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    func result(){
        count++
        time.text = String(count)
    }

}

