
/****************************************************

                     Example Blow:

****************************************************/

#include "MKit.h"
#include "curl.h"
#if 0

int main (int   argc, char *argv[])
{
    /* In windows, this will init the winsock stuff */
    curl_global_init(CURL_GLOBAL_ALL);
    {
        CURL *curl = NULL;
        CURLcode res;
        struct curl_slist *list = NULL;
        MSCOPEDDELETER(pp,curl_slist_free_all,&list);

        //new CURL
        curl = curl_easy_init();
        MSCOPEDDELETER(p,curl_easy_cleanup,&curl);
        if(curl) {
            //set url
            curl_easy_setopt(curl, CURLOPT_URL, "http://jd.com/");
            //set post data
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");

            //add header
            list = curl_slist_append(list, "Shoesize: 10");
            list = curl_slist_append(list, "Accept:");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5);//超时设置
            curl_easy_setopt(locHandle, CURLOPT_TCP_KEEPALIVE, 1L);

            //
            //curl_easy_setopt(curl,CURLOPT_HEADER,1);

            //get return data
            QByteArray retHeader;
            QByteArray retBody;
            auto writeCallback = [](char *buffer,size_t size,size_t nitems,void *outstream){
                QByteArray *out = (QByteArray *)outstream;
                out->append(buffer,size * nitems);
                return size * nitems;
            };
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,(curl_write_callback)writeCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &retBody);
            curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, (curl_write_callback)writeCallback);
            curl_easy_setopt(curl, CURLOPT_HEADERDATA, &retHeader);

            //do post
            res = curl_easy_perform(curl);
            /* Check for errors */
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n",
                        curl_easy_strerror(res));
            //print return data
            MDG << retHeader
                << retBody
                << retHeader.length()
                << retBody.length()
                << MTL::get_hex_str_format_from_QByteArray(retHeader)
                << MTL::get_hex_str_format_from_QByteArray(retBody);
            //get header
            char *ct = NULL;
            res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
            if(!res && ct) {
                printf("Content-Type: %s\n", ct);
            }
        }
    }
    curl_global_cleanup();
}
#endif //0
