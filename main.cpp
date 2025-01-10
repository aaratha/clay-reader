#include <cstdint>

#include "renderers/raylib/raylib.h"
#define CLAY_IMPLEMENTATION

#include "clay.h"
#include "renderers/raylib/clay_renderer_raylib.c"

const int FONT_ID_BODY_16 = 0;
Clay_Color COLOR_WHITE = {255, 255, 255, 255};

void HandleClayErrors(Clay_ErrorData errorData) {
    printf("%s", errorData.errorText.chars);
}

void RenderHeaderButton(Clay_String text) {
    CLAY(CLAY_LAYOUT({.padding = {16, 8}}),
         CLAY_RECTANGLE({.color = {140, 140, 140, 255}, .cornerRadius = 5})) {
        CLAY_TEXT(text,
                  CLAY_TEXT_CONFIG({.fontId = FONT_ID_BODY_16,
                                    .fontSize = 16,
                                    .textColor = {255, 255, 255, 255}}));
    }
}

typedef struct {
    Clay_String title;
    Clay_String contents;
} Document;

typedef struct {
    Document* documents;
    size_t length;
} DocumentArray;

DocumentArray documents = {
    .documents =
        NULL,  // TODO figure out if it's possible to const init this list
    .length = 5};

size_t selectedDocumentIndex = 0;

void HandleSidebarInteraction(Clay_ElementId elementID,
                              Clay_PointerData pointerData,
                              intptr_t userData) {
    if (pointerData.state == CLAY_POINTER_DATA_PRESSED_THIS_FRAME) {
        if (userData >= 0 && userData < documents.length) {
            selectedDocumentIndex = userData;
        }
    }
}

int main(void) {
    documents.documents = (Document[]){
        {.title = CLAY_STRING("Squirrels"),
         .contents = CLAY_STRING(
             "The Secret Life of Squirrels: Nature's Clever Acrobats\n"
             "Squirrels are often overlooked creatures, dismissed as mere park "
             "inhabitants or backyard nuisances. Yet, beneath their fluffy "
             "tails and twitching noses lies an intricate world of cunning, "
             "agility, and survival tactics that are nothing short of "
             "fascinating. As one of the most common mammals in North America, "
             "squirrels have adapted to a wide range of environments from "
             "bustling urban centers to tranquil forests and have developed a "
             "variety of unique behaviors that continue to intrigue scientists "
             "and nature enthusiasts alike.\n"
             "\n"
             "Master Tree Climbers\n"
             "At the heart of a squirrel's skill set is its impressive ability "
             "to navigate trees with ease. Whether they're darting from branch "
             "to branch or leaping across wide gaps, squirrels possess an "
             "innate talent for acrobatics. Their powerful hind legs, which "
             "are longer than their front legs, give them remarkable jumping "
             "power. With a tail that acts as a counterbalance, squirrels can "
             "leap distances of up to ten times the length of their body, "
             "making them some of the best aerial acrobats in the animal "
             "kingdom.\n"
             "But it's not just their agility that makes them exceptional "
             "climbers. Squirrels' sharp, curved claws allow them to grip tree "
             "bark with precision, while the soft pads on their feet provide "
             "traction on slippery surfaces. Their ability to run at high "
             "speeds and scale vertical trunks with ease is a testament to the "
             "evolutionary adaptations that have made them so successful in "
             "their arboreal habitats.\n"
             "\n"
             "Food Hoarders Extraordinaire\n"
             "Squirrels are often seen frantically gathering nuts, seeds, and "
             "even fungi in preparation for winter. While this behavior may "
             "seem like instinctual hoarding, it is actually a survival "
             "strategy that has been honed over millions of years. Known as "
             "\"scatter hoarding,\" squirrels store their food in a variety of "
             "hidden locations, often burying it deep in the soil or stashing "
             "it in hollowed-out tree trunks.\n"
             "Interestingly, squirrels have an incredible memory for the "
             "locations of their caches. Research has shown that they can "
             "remember thousands of hiding spots, often returning to them "
             "months later when food is scarce. However, they don't always "
             "recover every stash some forgotten caches eventually sprout into "
             "new trees, contributing to forest regeneration. This "
             "unintentional role as forest gardeners highlights the ecological "
             "importance of squirrels in their ecosystems.\n"
             "\n"
             "The Great Squirrel Debate: Urban vs. Wild\n"
             "While squirrels are most commonly associated with rural or "
             "wooded areas, their adaptability has allowed them to thrive in "
             "urban environments as well. In cities, squirrels have become "
             "adept at finding food sources in places like parks, streets, and "
             "even garbage cans. However, their urban counterparts face unique "
             "challenges, including traffic, predators, and the lack of "
             "natural shelters. Despite these obstacles, squirrels in urban "
             "areas are often observed using human infrastructure such as "
             "buildings, bridges, and power lines as highways for their "
             "acrobatic escapades.\n"
             "There is, however, a growing concern regarding the impact of "
             "urban life on squirrel populations. Pollution, deforestation, "
             "and the loss of natural habitats are making it more difficult "
             "for squirrels to find adequate food and shelter. As a result, "
             "conservationists are focusing on creating squirrel-friendly "
             "spaces within cities, with the goal of ensuring these "
             "resourceful creatures continue to thrive in both rural and urban "
             "landscapes.\n"
             "\n"
             "A Symbol of Resilience\n"
             "In many cultures, squirrels are symbols of resourcefulness, "
             "adaptability, and preparation. Their ability to thrive in a "
             "variety of environments while navigating challenges with agility "
             "and grace serves as a reminder of the resilience inherent in "
             "nature. Whether you encounter them in a quiet forest, a city "
             "park, or your own backyard, squirrels are creatures that never "
             "fail to amaze with their endless energy and ingenuity.\n"
             "In the end, squirrels may be small, but they are mighty in their "
             "ability to survive and thrive in a world that is constantly "
             "changing. So next time you spot one hopping across a branch or "
             "darting across your lawn, take a moment to appreciate the "
             "remarkable acrobat at work a true marvel of the natural "
             "world.\n")},
        {.title = CLAY_STRING("Lorem Ipsum"),
         .contents = CLAY_STRING(
             "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
             "eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut "
             "enim ad minim veniam, quis nostrud exercitation ullamco laboris "
             "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor "
             "in reprehenderit in voluptate velit esse cillum dolore eu fugiat "
             "nulla pariatur. Excepteur sint occaecat cupidatat non proident, "
             "sunt in culpa qui officia deserunt mollit anim id est laborum.")},
        {.title = CLAY_STRING("Vacuum Instructions"),
         .contents = CLAY_STRING(
             "Chapter 3: Getting Started - Unpacking and Setup\n"
             "\n"
             "Congratulations on your new SuperClean Pro 5000 vacuum cleaner! "
             "In this section, we will guide you through the simple steps to "
             "get your vacuum up and running. Before you begin, please ensure "
             "that you have all the components listed in the \"Package "
             "Contents\" section on page 2.\n"
             "\n"
             "1. Unboxing Your Vacuum\n"
             "Carefully remove the vacuum cleaner from the box. Avoid using "
             "sharp objects that could damage the product. Once removed, place "
             "the unit on a flat, stable surface to proceed with the setup. "
             "Inside the box, you should find:\n"
             "\n"
             "    The main vacuum unit\n"
             "    A telescoping extension wand\n"
             "    A set of specialized cleaning tools (crevice tool, "
             "upholstery brush, etc.)\n"
             "    A reusable dust bag (if applicable)\n"
             "    A power cord with a 3-prong plug\n"
             "    A set of quick-start instructions\n"
             "\n"
             "2. Assembling Your Vacuum\n"
             "Begin by attaching the extension wand to the main body of the "
             "vacuum cleaner. Line up the connectors and twist the wand into "
             "place until you hear a click. Next, select the desired cleaning "
             "tool and firmly attach it to the wand's end, ensuring it is "
             "securely locked in.\n"
             "\n"
             "For models that require a dust bag, slide the bag into the "
             "compartment at the back of the vacuum, making sure it is "
             "properly aligned with the internal mechanism. If your vacuum "
             "uses a bagless system, ensure the dust container is correctly "
             "seated and locked in place before use.\n"
             "\n"
             "3. Powering On\n"
             "To start the vacuum, plug the power cord into a grounded "
             "electrical outlet. Once plugged in, locate the power switch, "
             "usually positioned on the side of the handle or body of the "
             "unit, depending on your model. Press the switch to the \"On\" "
             "position, and you should hear the motor begin to hum. If the "
             "vacuum does not power on, check that the power cord is securely "
             "plugged in, and ensure there are no blockages in the power "
             "switch.\n"
             "\n"
             "Note: Before first use, ensure that the vacuum filter (if your "
             "model has one) is properly installed. If unsure, refer to "
             "\"Section 5: Maintenance\" for filter installation "
             "instructions.")},
        {.title = CLAY_STRING("Article 4"),
         .contents = CLAY_STRING("Article 4")},
        {.title = CLAY_STRING("Article 5"),
         .contents = CLAY_STRING("Article 5")},
    };

    Clay_Raylib_Initialize(
        1024,
        768,
        "Introducing Clay Demo",
        FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT |
            FLAG_VSYNC_HINT);  // Extra parameters to this function are new
                               // since the video was published

    uint64_t clayRequiredMemory = Clay_MinMemorySize();

    Clay_Arena clayMemory = Clay_CreateArenaWithCapacityAndMemory(
        clayRequiredMemory, malloc(clayRequiredMemory));

    Clay_Initialize(clayMemory,
                    (Clay_Dimensions){.width = float(GetScreenWidth()),
                                      .height = float(GetScreenHeight())},
                    (Clay_ErrorHandler){HandleClayErrors});

    Clay_SetMeasureTextFunction(Raylib_MeasureText);
    Raylib_fonts[FONT_ID_BODY_16] = (Raylib_Font){
        .font = LoadFontEx("resources/Roboto-Regular.ttf", 48, 0, 400),
        .fontId = FONT_ID_BODY_16};

    while (!WindowShouldClose()) {
        Clay_SetLayoutDimensions(
            (Clay_Dimensions){.width = float(GetScreenWidth()),
                              .height = float(GetScreenHeight())});

        Vector2 mousePosition = GetMousePosition();
        Vector2 scrollDelta = GetMouseWheelMoveV();
        Clay_SetPointerState((Clay_Vector2){mousePosition.x, mousePosition.y},
                             IsMouseButtonDown(0));
        Clay_UpdateScrollContainers(
            true, (Clay_Vector2){scrollDelta.x, scrollDelta.y}, GetFrameTime());

        Clay_Sizing layoutExpand = {.width = CLAY_SIZING_GROW(),
                                    .height = CLAY_SIZING_GROW()};

        Clay_RectangleElementConfig contentBackgroundConfig = {
            .color = {90, 90, 90, 255}, .cornerRadius = 10};

        Clay_BeginLayout();

        CLAY(CLAY_ID("OuterContainter"),
             CLAY_RECTANGLE({.color = {0, 0, 0, 255}}),
             CLAY_LAYOUT({.layoutDirection = CLAY_TOP_TO_BOTTOM,
                          .sizing = layoutExpand,
                          .padding = {16, 16},
                          .childGap = 16})) {
            CLAY(CLAY_ID("HeaderBar"),
                 CLAY_RECTANGLE(contentBackgroundConfig),
                 CLAY_LAYOUT({.sizing = {.height = CLAY_SIZING_FIXED(60),
                                         .width = CLAY_SIZING_GROW()},
                              .padding = {.x = 16},
                              .childGap = 16,
                              .childAlignment = {.y = CLAY_ALIGN_Y_CENTER}

                 })) {
                RenderHeaderButton(CLAY_STRING("File"));
                RenderHeaderButton(CLAY_STRING("Edit"));
                RenderHeaderButton(CLAY_STRING("View"));
                CLAY(CLAY_LAYOUT({.sizing = {CLAY_SIZING_GROW()}})) {}
                RenderHeaderButton(CLAY_STRING("Upload"));
                RenderHeaderButton(CLAY_STRING("Help"));
            }
            CLAY(CLAY_ID("LowerContent"),
                 CLAY_LAYOUT({.sizing = layoutExpand, .childGap = 16})) {
                CLAY(CLAY_ID("Sidebar"),
                     CLAY_RECTANGLE(contentBackgroundConfig),
                     CLAY_LAYOUT({
                         .layoutDirection = CLAY_TOP_TO_BOTTOM,
                         .padding = {16, 16},
                         .childGap = 8,
                         .sizing = {.width = CLAY_SIZING_FIXED(200),
                                    .height = CLAY_SIZING_GROW()},
                     })) {
                    // Render document titles here
                    for (int i = 0; i < documents.length; i++) {
                        Document document = documents.documents[i];
                        Clay_LayoutConfig sidebarButtonLayout = {
                            .sizing = {.width = CLAY_SIZING_GROW()},
                            .padding = {16, 16}};
                        if (i == selectedDocumentIndex) {
                            CLAY(CLAY_LAYOUT(sidebarButtonLayout),
                                 CLAY_RECTANGLE({.color = {120, 120, 120, 255},
                                                 .cornerRadius = 8})) {
                                CLAY_TEXT(document.title,
                                          CLAY_TEXT_CONFIG(
                                              {.fontId = FONT_ID_BODY_16,
                                               .fontSize = 20,
                                               .textColor = COLOR_WHITE}));
                            }
                        } else {
                            CLAY(CLAY_LAYOUT(sidebarButtonLayout),
                                 Clay_OnHover(HandleSidebarInteraction, i),
                                 Clay_Hovered()
                                     ? CLAY_RECTANGLE(
                                           {.color = {120, 120, 120, 120},
                                            .cornerRadius = 8})
                                     : CLAY_RECTANGLE(
                                           {.color = {120, 120, 120, 0},
                                            .cornerRadius = 8})) {
                                CLAY_TEXT(document.title,
                                          CLAY_TEXT_CONFIG(
                                              {.fontId = FONT_ID_BODY_16,
                                               .fontSize = 20,
                                               .textColor = COLOR_WHITE}));
                            }
                        }
                    }
                }
                CLAY(CLAY_ID("MainContent"),
                     CLAY_RECTANGLE(contentBackgroundConfig),
                     CLAY_SCROLL({.vertical = true}),
                     CLAY_LAYOUT({
                         .layoutDirection = CLAY_TOP_TO_BOTTOM,
                         .padding = {16, 16},
                         .childGap = 16,
                         .sizing = layoutExpand,
                     })) {
                    Document selectedDocument =
                        documents.documents[selectedDocumentIndex];
                    CLAY_TEXT(selectedDocument.title,
                              CLAY_TEXT_CONFIG({.fontId = FONT_ID_BODY_16,
                                                .fontSize = 24,
                                                .textColor = COLOR_WHITE}));
                    CLAY_TEXT(selectedDocument.contents,
                              CLAY_TEXT_CONFIG({.fontId = FONT_ID_BODY_16,
                                                .fontSize = 24,
                                                .textColor = COLOR_WHITE}));
                }
            }
        }

        Clay_RenderCommandArray renderCommands = Clay_EndLayout();

        BeginDrawing();
        ClearBackground(BLACK);
        Clay_Raylib_Render(renderCommands);
        EndDrawing();
    }
}