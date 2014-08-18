#import "NativeTwitter.h"
#import <Twitter/Twitter.h>
void NativeTwitter::openTweetDialog(const char* $tweet)
{
    NSString* tweet = [NSString stringWithUTF8String:$tweet];
    if([TWTweetComposeViewController canSendTweet]){
        UIViewController *myViewController = [UIApplication sharedApplication].keyWindow.rootViewController;
        TWTweetComposeViewController *twitterVC = [[TWTweetComposeViewController alloc] init];
        twitterVC.completionHandler = ^(TWTweetComposeViewControllerResult res){
            [myViewController dismissViewControllerAnimated:YES completion: nil];
        };
        
        [myViewController presentViewController: twitterVC animated:YES completion: nil];
    } else {
        tweet = [NSString stringWithFormat: @"%@%@",@"http://twitter.com/intent/tweet?text=",tweet];
        tweet = [tweet stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:tweet]];
    }
    tweet = nil;
}
