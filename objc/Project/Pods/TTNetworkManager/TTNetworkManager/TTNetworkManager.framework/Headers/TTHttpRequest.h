
#import <Foundation/Foundation.h>

@interface TTHttpRequest : NSObject

/*!
 @property HTTPMethod
 @abstract Returns the HTTP request method of the receiver.
 @result the HTTP request method of the receiver.
 */
@property (nullable, copy) NSString *HTTPMethod;

/*!
 @property URL
 @abstract Sets the URL of the receiver.
 @result URL The new URL for the receiver.
 */
@property (nullable, copy) NSURL *URL;

/*!
 @property setTimeoutInterval:
 @abstract Sets the timeout interval of the receiver.
 @discussion The timeout interval specifies the limit on the idle
 interval allotted to a request in the process of loading. The "idle
 interval" is defined as the period of time that has passed since the
 last instance of load activity occurred for a request that is in the
 process of loading. Hence, when an instance of load activity occurs
 (e.g. bytes are received from the network for a request), the idle
 interval for a request is reset to 0. If the idle interval ever
 becomes greater than or equal to the timeout interval, the request
 is considered to have timed out. This timeout interval is measured
 in seconds.
 @result seconds The new timeout interval of the receiver.
 */
@property (assign) NSTimeInterval timeoutInterval;

/*!
 @property HTTPBody
 @abstract Returns the request body data of the receiver.
 @discussion This data is sent as the message body of the request, as
 in done in an HTTP POST request.
 @result The request body data of the receiver.
 */
@property (nullable, copy) NSData *HTTPBody;

/*!
 @property uploadFilePath
 @abstract Returns the upload file path.
 @discussion This path target file is sent as the message body of the request, as
 in done in an HTTP POST request.
 @result The upload file path.
 */
@property (nullable, copy) NSString *uploadFilePath;

/*!
 @property allHTTPHeaderFields
 @abstract Returns a dictionary containing all the HTTP header fields
 of the receiver.
 @result a dictionary containing all the HTTP header fields of the
 receiver.
 */
@property (nullable, copy) NSDictionary<NSString *, NSString *> *allHTTPHeaderFields;

/*!
 @property followRedirect
 @abstract set boolean value means if follow 3xx http redirection.
 @result true follow redirection.
 */
@property (assign) BOOL followRedirect;

/*!
 @method valueForHTTPHeaderField:
 @abstract Returns the value which corresponds to the given header
 field. Note that, in keeping with the HTTP RFC, HTTP header field
 names are case-insensitive.
 @param field the header field name to use for the lookup
 (case-insensitive).
 @result the value associated with the given header field, or nil if
 there is no value associated with the given header field.
 */
- (nullable NSString *)valueForHTTPHeaderField:(nonnull NSString *)field;

/*!
 @method setValue:forHTTPHeaderField:
 @abstract Sets the value of the given HTTP header field.
 @discussion If a value was previously set for the given header
 field, that value is replaced with the given value. Note that, in
 keeping with the HTTP RFC, HTTP header field names are
 case-insensitive.
 @param value the header field value.
 @param field the header field name (case-insensitive).
 */
- (void)setValue:(nullable NSString *)value forHTTPHeaderField:(nonnull NSString *)field;

/*!
 @method addValue:forHTTPHeaderField:
 @abstract Adds an HTTP header field in the current header
 dictionary.
 @discussion This method provides a way to add values to header
 fields incrementally. If a value was previously set for the given
 header field, the given value is appended to the previously-existing
 value. The appropriate field delimiter, a comma in the case of HTTP,
 is added by the implementation, and should not be added to the given
 value by the caller. Note that, in keeping with the HTTP RFC, HTTP
 header field names are case-insensitive.
 @param value the header field value.
 @param field the header field name (case-insensitive).
 */
- (void)addValue:(nonnull NSString *)value forHTTPHeaderField:(nonnull NSString *)field;

@end
