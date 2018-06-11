//
//  ViewController.m
//  Sha1AndMD5Test
//
//  Created by peony on 2018/6/11.
//  Copyright © 2018年 peony. All rights reserved.
//

#import "ViewController.h"
#import "LJJ_MD5AndSha1Handle.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextField *inputTextFiled;
@property (weak, nonatomic) IBOutlet UIButton *MD5Button;
@property (weak, nonatomic) IBOutlet UIButton *sha1Button;
@property (weak, nonatomic) IBOutlet UILabel *showLabel;
@property (copy,nonatomic) NSString *inputString;

 @property (copy,nonatomic) NSString *hashType;//nil、MD5 or sha1

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    NSString *shaOne = [LJJ_MD5AndSha1Handle LJJ_sha1:@"1"];
    NSString *MD5One = [LJJ_MD5AndSha1Handle LJJ_MD5:@"1"];
    NSString *shaTwo = [LJJ_MD5AndSha1Handle LJJ_sha1:@"1"];
    NSString *MD5Two = [LJJ_MD5AndSha1Handle LJJ_MD5:@"1"];
    NSLog(@"\nshaOne:%@\nMD5One:%@\nshaTwo:%@\nMD5Two:%@\n",shaOne,MD5One,shaTwo,MD5Two);
    
    [self roundedRectImageViewWithCornerRadius:8.0 view:self.MD5Button];
    [self roundedRectImageViewWithCornerRadius:8.0 view:self.sha1Button];
    
    
}
- (IBAction)MD5ButtonClick:(id)sender {
    [self.inputTextFiled resignFirstResponder];
    if (self.inputTextFiled.text.length > 0 && (![self.inputTextFiled.text isEqualToString:self.inputString] || ![self.hashType isEqualToString:@"MD5"])) {
        @try {
            self.hashType = @"MD5";
            self.inputString = self.inputTextFiled.text;
            dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
                
                NSString *MD5String = [LJJ_MD5AndSha1Handle LJJ_MD5:self.inputString];
                dispatch_async(dispatch_get_main_queue(), ^{
                    self.showLabel.text = MD5String;
                    [self.showLabel setNeedsDisplay];
                });
                
            });
        }@catch (NSException *exception) {
            NSLog(@"MD5出错：%@",exception);
        }
        
    }else {
        NSLog(@"未输入或未改变");
    }
}
- (IBAction)sha1ButtonClick:(id)sender {
    [self.inputTextFiled resignFirstResponder];
    if (self.inputTextFiled.text.length > 0 && (![self.inputTextFiled.text isEqualToString:self.inputString]  || ![self.hashType isEqualToString:@"sha1"])) {
        @try {
            self.hashType = @"sha1";
            self.inputString = self.inputTextFiled.text;
            dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
                
                NSString *sha1String = [LJJ_MD5AndSha1Handle LJJ_sha1:self.inputString];
                dispatch_async(dispatch_get_main_queue(), ^{
                    self.showLabel.text = sha1String;
//                    [self.showLabel needsUpdateConstraints];
                });
                
            });
        }@catch (NSException *exception) {
            NSLog(@"sha1出错：%@",exception);
        }
        
    }else {
        NSLog(@"未输入或未改变");
    }
}



- (void)roundedRectImageViewWithCornerRadius:(CGFloat)cornerRadius view:(UIView *)view{
    UIBezierPath *bezierPath = [UIBezierPath bezierPathWithRoundedRect:view.bounds cornerRadius:cornerRadius];
    CAShapeLayer *layer = [CAShapeLayer layer];
    layer.path = bezierPath.CGPath;
    view.layer.mask = layer;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
