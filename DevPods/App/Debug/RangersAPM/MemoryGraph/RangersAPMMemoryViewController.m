//
//  RangersAPMMemoryViewController.m
//  RangersAPM_iOS
//
//  Created by xuminghao.eric on 2020/11/12.
//

#import "RangersAPMMemoryViewController.h"
#import "RangersAPMCellItem.h"
#import <mach/mach.h>

static float dangerousMemoryThreshold = 512.0;

bool overMemoryThreshold(void)
{
    kern_return_t kr;

    task_vm_info_data_t task_vm;
    mach_msg_type_number_t task_vm_count = TASK_VM_INFO_COUNT;
    kr = task_info(mach_task_self(), TASK_VM_INFO, (task_info_t) &task_vm, &task_vm_count);

    if (kr == KERN_SUCCESS) {
        printf("RangersAPM Debug Log : Current App Memory is :%f\n\n", task_vm.phys_footprint / (1024.0 * 1024.0));
        if (task_vm.phys_footprint / (1024.0 * 1024.0) > dangerousMemoryThreshold) {
            return true;
        } else {
            return false;
        }
    }

    return false;
}

@interface RangersAPMMemoryViewController ()<UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) UITableView *tableView;

@property (nonatomic, copy) NSMutableArray *items;

@end

@implementation RangersAPMMemoryViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
    [self.tableView registerClass:UITableViewCell.class forCellReuseIdentifier:@"RangersAPMMemoryCell"];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    self.tableView.tableFooterView = [[UIView alloc] initWithFrame:CGRectZero];
    [self.view addSubview:self.tableView];
    
    self.title = @"εε­δΌε";
    // Do any additional setup after loading the view.
}

#pragma mark UITableViewDelegate, UITableViewDelegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.items.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"RangersAPMMemoryCell"];
    RangersAPMCellItem *item = [self.items objectAtIndex:indexPath.row];
    cell.textLabel.text = [NSString stringWithFormat:@"%@",item.title];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    RangersAPMCellItem *item = [self.items objectAtIndex:indexPath.row];
    if (item.selectBlock) {
        item.selectBlock();
    }
}

#pragma mark - Lazy-load
- (NSMutableArray *)items {
    if (!_items) {
        _items = [[NSMutableArray alloc] init];
        
        __weak typeof(self) weakSelf = self;
        
        void(^memoryTriggerBlock)(void) = ^{
            __strong typeof(self) strongSelf = weakSelf;
            if (strongSelf) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"θ§¦εεε­ζ³ζΌ" message:@"ηΉε»η‘?ε?εΌε§θ§¦εεε­ζ³ζΌοΌε½APPε η¨εε­θΆθΏ512MBζΆδΌθ§¦εεε­εζοΌε¨ζδΊζε΅δΈοΌε―θ½APPεε­ζ²‘ζθΎΎε°512MBε°±θ’«η³»η»KILLοΌε¦ζζͺζΆε°εε­εζζεζη€ΊοΌε€§ζ¦5sδΉεοΌοΌθ―·ιζ°ε―ε¨APPθ§¦εζ³ζΌγ" preferredStyle:UIAlertControllerStyleAlert];
                    UIAlertAction *ok = [UIAlertAction actionWithTitle:@"η‘?ε?" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                        while (1) {
                            if (!overMemoryThreshold()) {
                                CGSize size = CGSizeMake(1024 * 8, 1024 * 8 * 9.0f/16.0);
                                const size_t bitsPerComponent = 8;
                                const size_t bytesPerRow = size.width * 4;
                                CGContextRef ctx = CGBitmapContextCreate(calloc(sizeof(unsigned char), bytesPerRow * size.height), size.width, size.height, bitsPerComponent, bytesPerRow, CGColorSpaceCreateDeviceRGB(), kCGImageAlphaPremultipliedLast);
                                CGContextSetRGBFillColor(ctx, 1.0, 1.0, 1.0, 1.0);
                                CGContextFillRect(ctx, CGRectMake(0, 0, size.width, size.height));
                            } else {
                                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                                    UIAlertController *successAlert = [UIAlertController alertControllerWithTitle:@"εε­εζε?ζ" message:@"θ―·ιζ°ε―ε¨APPοΌηΆεAPPδΌθͺε¨δΈζ₯εε­ζ₯εΏοΌη±δΊε­ε¨ιζ ·οΌε―θ½ιθ¦ε€ζ¬‘ε―ε¨ζε―ζεδΈζ₯οΌε·δ½ε―δ»₯ζ₯ηεΈ?ε©ζζ‘£γ" preferredStyle:UIAlertControllerStyleAlert];
                                    UIAlertAction *okk = [UIAlertAction actionWithTitle:@"η‘?ε?" style:UIAlertActionStyleDefault handler:nil];
                                    [successAlert addAction:okk];
                                    [strongSelf presentViewController:successAlert animated:YES completion:nil];
                                });
                                break;
                            }
                        }
                    }];
                    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"εζΆ" style:UIAlertActionStyleCancel handler:nil];
                    [alert addAction:ok];
                    [alert addAction:cancel];
                    [strongSelf presentViewController:alert animated:YES completion:nil];
                });
            }
        };
        RangersAPMCellItem *memoryTriggerItem = [RangersAPMCellItem itemWithTitle:@"ζ΅θ―εε­δΌεοΌζ³ζΌγε€§ε―Ήθ±‘γεθ?Ύε€ζ₯θ―’οΌ" block:memoryTriggerBlock];
        
        [_items addObject:memoryTriggerItem];
    }
    return _items;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
