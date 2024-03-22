#include "PanelRightSide.hpp"

#include "side_panel_helpers.hpp"

PanelRightSide::PanelRightSide(QWidget *parent)
    : SidePanel(parent)
{

    this->getOpenedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_opened_right(this->getPanelSize(), parent_rect);
    };

    this->getClosedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_closed_right(this->getPanelSize(), parent_rect);
    };

    this->alignedHandlerRect = [](const QRect& panel_geom, const QSize& handler_size, qreal) -> QRect
    {
        return q_sp::rect_aligned_left_center(panel_geom, handler_size);
    };

    this->initialHandlerSize = []() -> QSize {
        return {30, 30};
    };

    this->updateHandler = [](const SidePanelState state, HandlerWidgetT* handler)
    {
        switch (state) {
        case SidePanelState::Opening: {
            QPixmap pixmap(":/img/img/prompt_suggestion_FILL0_wght400_GRAD0_opsz24.svg");
            handler->setIcon(QIcon(pixmap));
            handler->setIconSize(pixmap.size());
        } break;
        case SidePanelState::Opened:  {
            QPixmap pixmap(":/img/img/prompt_suggestion_FILL0_wght400_GRAD0_opsz24.svg");
            handler->setIcon(QIcon(pixmap));
            handler->setIconSize(pixmap.size());} break;
        case SidePanelState::Closing: {
            QPixmap pixmap(":/img/img/settings_FILL0_wght400_GRAD0_opsz24.svg");
            handler->setIcon(QIcon(pixmap));
            handler->setIconSize(pixmap.size()); } break;
        case SidePanelState::Closed:  {
            QPixmap pixmap(":/img/img/settings_FILL0_wght400_GRAD0_opsz24.svg");
            handler->setIcon(QIcon(pixmap));
            handler->setIconSize(pixmap.size());} break;
        default: break;
        }
    };

}

PanelRightSide::~PanelRightSide()
{

}
