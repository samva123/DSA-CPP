//import config from "../postcss.config.mjs";

import { NextResponse } from "next/server";

const publicRoutes = ['/login' , '/signup' , '/public'];

export function middleware(request) {
    const token = request.cookies.get('token')?.value;

    let isPublic = false;

    publicRoutes.forEach((route) => {
        if(request.nextUrl.pathname.startsWith(route)){
            isPublic = true;
        }
    });

    

    if(!token && !isPublic){
        return NextResponse.redirect(new URL('/login' , request.url));
    }

  // Middleware logic can be added here if needed
  //return;
}

// negative matching for api , _next/static , _next/image , favicon.ico , sitemap.xml , robots.txt means 
// all other paths will be matched except these paths
export const config = {
    matcher: ['/((?!api|_next/static|_next/image|favicon.ico|sitemap.xml|robots.txt).*)']
}


