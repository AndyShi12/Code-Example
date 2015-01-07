//
//  ViewController.swift
//  Tic Tac Toe
//
//  Created by Andy Shi on 1/3/15.
//  Copyright (c) 2015 Andy Shi. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    var turn = 1
    
    // 0 = empty, 1 = O, 2 = X
    var gameState = [0,0,0,0,0,0,0,0,0]
    let win = [[0,1,2],[3,4,5],[6,7,8],[0,3,6],[1,4,7],[2,5,8],[0,4,8],[2,4,6]]
    var winner = 0
    
    @IBOutlet var winnerLabel: UILabel!
    @IBOutlet var button0: UIButton!
    @IBAction func buttonPressed(sender: AnyObject) {
        
        if (gameState[sender.tag] == 0 && winner == 0){
        
        var image = UIImage(named: "knot.png")
        
        if (turn % 2 == 0)
        {
            image = UIImage(named: "cross.png")
            gameState[sender.tag] = 2
        }
        else {
            image = UIImage(named: "knot.png")
            gameState[sender.tag] = 1
        }
        turn++
        sender.setImage(image, forState: .Normal)
        }
        
        for combo in win {
           // println(" \(gameState[combo[0]]) \(gameState[combo[1]]) \(gameState[combo[2]]) ")
            if (gameState[combo[0]] == gameState[combo[1]])
            && (gameState[combo[1]] == gameState[combo[2]])
            && (gameState[combo[1]] != 0)
            {
                winner = gameState[combo[0]]
            }
        }
        
        if(winner != 0)
        {
            if (winner == 1)
            {
                winnerLabel.text = "O wins!"
            }
            else
            {
                winnerLabel.text = "X wins!"
            }
            
            UIView.animateWithDuration(1,
                animations: {
                    self.winnerLabel.center = CGPointMake(self.winnerLabel.center.x + 400, self.winnerLabel.center.y+400)
                })
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
    
    override func viewDidAppear(animated: Bool) {
       winnerLabel.center = CGPointMake(winnerLabel.center.x - 400, winnerLabel.center.y-400)
    }


}

